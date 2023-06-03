import re
import json

def between_parens(test_str):
    test_str=test_str.replace("(","*(")
    test_str=test_str.replace(")",")*")
    x=test_str.split("*")
    res=[]
    for i in x:
        if i.startswith("(") and i.endswith(")"):
            res.append(i)
    return res

def strip_extras(str):
  res, n = re.subn('[ \t\r\n\f()]', '', str)
  return res



s = """

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   */
  [_BASE] = LAYOUT(
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      RAISE,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC, KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      KC_LCTL, KC_LCTL, KC_LGUI, KC_LALT, QK_LEAD, LOWER,  LT_LO_SP, LT_RA_SP,RAISE,   KC_RSFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
      ),

  /* Lower
   */
  [_LOWER] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
      KC_F12,  KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, NEWTAB,                    KC_MINUS,KC_EQUAL,_______, DM_REC1, DM_PLY1, KC_F11,
      _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_PGUP,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_BTN2,
      _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_HOME, KC_END,  KC_LPRN, KC_RPRN, KC_HOME, KC_END,  _______, _______, KC_DEL,  _______,
      _______, _______, _______, _______, _______, _______, KC_ENT,   UPSPC,  _______, _______, _______, _______, _______, _______
      ),

  /* Raise
   */
  [_RAISE] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_DEL,
      KC_F12,  UPDIR,   KC_UP,   SELWORD, KC_PGUP, NEWTAB,                    KC_UNDS, KC_PLUS, _______, _______,  _______, KC_F11,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_HOME,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
      _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_PGUP, KC_PGDN, KC_LPRN, KC_RPRN, KC_PGUP, KC_PGDN, _______,  KC_INSERT,KC_DEL, _______,
      _______, _______, _______, _______, _______, _______, KC_ENT,   UPSPC,  _______, _______, _______, _______,  _______, _______
      ),

  /* Adjust
   */
  [_ADJUST] =  LAYOUT(
      KC_GRV,  _______, _______, _______, _______, _______,                   _______, _______, KC_NUM,  _______, _______, KC_DEL,
      _______, QK_BOOT, _______, _______, _______, _______,                   RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______,
      KC_CAPS, KC_MAKE, _______, _______, _______, _______,                   RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______,
      _______, DB_TOGG, _______, _______, _______, _______, _______, _______, RGBRST,  _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      )
};
      """


padded_layer_strings = between_parens(s)

# for i in r:
#   res, n = re.subn('[ \t\r\n\f()]', '', i)
#   print(res)
# res = [re.subn('[ \t\r\n\f()]', '', i) for i in r]
layer_strings = [strip_extras(i) for i in padded_layer_strings]
# print(layer_strings)
layers = [i.split(",") for i in layer_strings]


di = {"version": 1, "notes": "",   "documentation": "\"This file is a QMK Configurator export. You can import this at <https://config.qmk.fm>. It can also be used directly with QMK's source code.\n\nTo setup your QMK environment check out the tutorial: <https://docs.qmk.fm/#/newbs>\n\nYou can convert this file to a keymap.c using this command: `qmk json2c {keymap}`\n\nYou can compile this keymap using this command: `qmk compile {keymap}`\"\n", "keyboard": "helix/rev2/qmk_conf", "keymap": "helix_rev2_qmk_conf_layout_mine", "layout": "LAYOUT", "layers": layers, "author": ""}

jst = json.dumps(di, indent=2)
with open("sample.json", "w") as outfile:
    json.dump(di, outfile, indent=2)
