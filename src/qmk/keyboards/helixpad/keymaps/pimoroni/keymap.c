#include QMK_KEYBOARD_H

enum layer_number {
  _BASE,
  _FN1
};
enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

#define FN1 TT(_FN1)
// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default layer
   *        ,-----------------------------------------.
   *        |   6  |   7  |   8  |   9  |   0  | Bksp |
   *        |------+------+------+------+------+------|
   *        |   Y  |   U  |   I  |   O  |   P  |  \   |
   *        |------+------+------+------+------+------|
   *        |   H  |   J  |   K  |   L  |   ;  |  '   |
   * ,------+------+------+------+------+------+------|
   * |   ]  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * /------+------+------+------+------+------+------|
   * |  SPC |  ALT |  CTL | Left | Down |  Up  |Right |
   * -------------------------------------------------'
   */

  [_BASE] = LAYOUT(
              KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,  KC_1,    KC_2,
              KC_P7,    KC_P8,    KC_P9,    KC_PPLS,  KC_VOLU, QK_REP,
              KC_P4,    KC_P5,    KC_P6,    KC_PENT,  KC_MUTE, QK_RBT,
    FN1,      KC_P1,    KC_P2,    KC_P3,    KC_RSFT,  KC_VOLD, QK_BOOT,
    FN1,      KC_RCTL,  KC_P0,     KC_PDOT,  KC_RALT,  QK_BOOT,     DRAG_SCROLL
  ),
  [_FN1] = LAYOUT(
              KC_CAPS, _______, _______, _______, _______, _______,
              RGB_MOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
              RGB_RMOD,RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
    _______,  _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, EE_CLR
  )
};

// clang-format on

bool set_scrolling = true;

void update_pimoroni_color(void) {
    if (set_scrolling) {
        pimoroni_trackball_set_rgbw(0, 254, 0, 0);
    } else {
        pimoroni_trackball_set_rgbw(128, 0, 128, 0);
    }
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DRAG_SCROLL && record->event.pressed) {
        set_scrolling = !set_scrolling;
    }
    update_pimoroni_color();
    return true;
}
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
  update_pimoroni_color();
}
