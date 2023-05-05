
// enum combos {
//     JK_TAB,
//     QW_SFT,
//     SD_LAYER,
//     EM_EMAIL,
//     BSPC_LSFT_CLEAR,
//     COMBO_ONEPW,
//     COMBO_LENGTH,
// };

// uint16_t COMBO_LEN = COMBO_LENGTH;

// const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
// const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM email_combo[] = {KC_E, KC_M, COMBO_END};
// const uint16_t PROGMEM clear_line_combo[] = {KC_BSPC, KC_LSFT, COMBO_END};
// const uint16_t PROGMEM one_password_combo[] = {KC_1, KC_P, KC_W, COMBO_END};

// combo_t key_combos[] = {
//   [JK_TAB] = COMBO(jk_combo, KC_TAB),
//   [QW_SFT] = COMBO(qw_combo, KC_LSFT),
//   [SD_LAYER] = COMBO(sd_combo, MO(FN2)),
//   [EM_EMAIL] = COMBO_ACTION(email_combo),
//   [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
//   [COMBO_ONEPW] = COMBO(one_password_combo, ONEPWD),
// };

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case EM_EMAIL:
//       if (pressed) {
//         SEND_STRING("apedley@gmail.com");
//       }
//       break;
//     case BSPC_LSFT_CLEAR:
//       if (pressed) {
//         tap_code16(KC_END);
//         tap_code16(S(KC_HOME));
//         tap_code16(KC_BSPC);
//       }
//       break;
//   }
// }
