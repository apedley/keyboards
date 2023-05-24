#include "bongo.h"
#include QMK_KEYBOARD_H


enum anim_states
{
    Idle,
    Prep,
    Tap
};

struct pair_int_int
{
    uint8_t first;
    uint8_t second;
};


uint8_t anim_state = Idle;
uint32_t idle_timeout_timer = 0;
uint32_t anim_timer = 0;
uint8_t current_idle_frame = 0;
uint8_t current_tap_frame = 0;

uint8_t pressed_keys_index = 0;

bool key_down = 0;
char wpm[42];


struct pair_int_int pressed_keys[KEYS_SIZE];
struct pair_int_int pressed_keys_prev[KEYS_SIZE];


bool detect_key_down(void)
{
    // store the previous cycle's cache
    for (uint8_t i = 0; i < KEYS_SIZE; ++i)
    {
        pressed_keys_prev[i].first = pressed_keys[i].first;
        pressed_keys_prev[i].second = pressed_keys[i].second;
    }

    // fill cache with currently pressed keys
    pressed_keys_index = 0;
    for (uint8_t x = 0; x < MATRIX_ROWS; x++)
    {
        for (uint8_t y = 0; y < MATRIX_COLS; y++)
        {
            // is this key is currently down?
            if (((matrix_get_row(x) & (1 << y)) > 0))
            {
                pressed_keys[pressed_keys_index].first = x+1; // adding 1 to the row/col so that we can use 0 as a null-check
                pressed_keys[pressed_keys_index].second = y+1;
            }
            else
            {
                pressed_keys[pressed_keys_index].first = 0;
                pressed_keys[pressed_keys_index].second = 0;
            }
            pressed_keys_index++;
        }
    }

    // check for a new key down compared to last cycle
    for (uint8_t i = 0; i < KEYS_SIZE; ++i)
    {
        if (pressed_keys[i].first && pressed_keys[i].second && !pressed_keys_prev[i].first && !pressed_keys_prev[i].second)
        {
            return true;
        }
    }
    return false;
}
void eval_anim_state(void)
{
    key_down = detect_key_down();

    switch (anim_state)
    {
        case Idle:
            if (key_down) // Idle to Tap
            {
                anim_state = Tap;
            }
            break;

        case Prep:
            if (key_down) // Prep to Tap
            {
                anim_state = Tap;
            }
            else if (timer_elapsed32(idle_timeout_timer) >= IDLE_TIMEOUT) // Prep to Idle
            {
                anim_state = Idle;
                current_idle_frame = 0;
            }
            break;

        case Tap:
            if (!key_down) // Tap to Prep
            {
                anim_state = Prep;
                idle_timeout_timer = timer_read32();
            }
            break;

        default:
            break;
    }
}

void render_bongo(bool minimal)
{
    eval_anim_state();

    oled_set_cursor(0, 0);

    switch (anim_state)
    {
        case Idle:
            if (minimal)
                oled_write_raw_P(idle_minimal[abs((IDLE_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
            else
                oled_write_raw_P(idle[abs((IDLE_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
            if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION)
            {
                current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
                anim_timer = timer_read32();
            }
            break;

        case Prep:
            if (minimal)
                oled_write_raw_P(prep_minimal[0], ANIM_SIZE);
            else
                oled_write_raw_P(prep[0], ANIM_SIZE);
            break;

        case Tap:
            if (minimal)
                oled_write_raw_P(tap_minimal[abs((TAP_FRAMES - 1) - current_tap_frame)], ANIM_SIZE);
            else
                oled_write_raw_P(tap[abs((TAP_FRAMES - 1) - current_tap_frame)], ANIM_SIZE);
            current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
            break;

        default:
            break;
    }

    if (!minimal)
    {
        // print wpm
        oled_set_cursor(0, 0);
        sprintf(wpm, "WPM:%03d", get_current_wpm());
        oled_write(wpm, false);

        // calculate && print clock
        oled_set_cursor(0, 2);
        // uint8_t  hour = last_minute / 60;
        // uint16_t minute = last_minute % 60;
        // bool is_pm = (hour / 12) > 0;
        // hour = hour % 12;
        // if (hour == 0) {
        //     hour = 12;
        // }
        static char time_str[8] = "TIMEHERE";
        // sprintf(time_str, "%02d:%02d%s", hour, minute, is_pm ? "pm" : "am");
        oled_write(time_str, false);
    }
}
