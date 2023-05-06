#include "apedley.h"
#include "print.h"
#include "features/select_word.h"

dynamic_macro_t dynamic_macro = {.recording = false };

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void dynamic_macro_record_start_user(void) {
    dynamic_macro.recording = true;
}

void dynamic_macro_record_end_user(int8_t direction) {
    dynamic_macro.recording = false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // #ifdef CONSOLE_ENABLE
    //     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    // #endif

    if (!process_select_word(keycode, record, SELWORD)) {
        return false;
    }

    const uint8_t mods         = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();


    switch (keycode) {
        case UPDIR: // Types ../ to go up a directory on the shell.
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;

        case BRACES: // Types [], {}, or <> and puts cursor between braces.
            if (record->event.pressed) {
                clear_oneshot_mods(); // Temporarily disable mods.
                unregister_mods(MOD_MASK_CSAG);
                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
                    SEND_STRING("{}");
                } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
                    SEND_STRING("()");
                } else {
                    SEND_STRING("[]");
                }
                tap_code(KC_LEFT);   // Move cursor between braces.
                register_mods(mods); // Restore mods.
            }
            return false;

        case SELLINE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
            }
            return false;
        // Compiles the keymap
        // Hold shift for falsh
        // Hold ctrl to add -j8 --output-sync
        case KC_MAKE:
            if (!record->event.pressed) {
                uint8_t temp_mod = mods;
                uint8_t temp_osm = oneshot_mods;
                clear_mods();
                clear_oneshot_mods();

                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
                    SEND_STRING("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP);
                } else {
                    SEND_STRING("qmk compile -kb " QMK_KEYBOARD " -km " QMK_KEYMAP);
                }

                if ((temp_mod | temp_osm) & MOD_MASK_CTRL) {
                    SEND_STRING(" -j8");
                }
                tap_code(KC_ENT);
                set_mods(temp_mod);
            }
            return false;
    }
    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
}

void keyboard_post_init_user() {

#ifdef CONSOLE_ENABLE
    debug_config.enable = true;
    // debug_config.keyboard = true;
    // debug_config.matrix = true;
#endif
}

void matrix_scan_user(void) {
    select_word_task();
}
