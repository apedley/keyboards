#include "apedley.h"
#include "features/select_word.h"
#include "print.h"

#ifdef RAW_ENABLE
#include "raw_hid.h"
#endif
dynamic_macro_t dynamic_macro = {.recording = false};

__attribute__((weak)) void matrix_scan_keymap(void) { return; }

__attribute__((weak)) bool process_record_keymap(uint16_t keycode,
                                                 keyrecord_t *record) {
  return true;
}

__attribute__((weak)) bool process_record_secrets(uint16_t keycode,
                                                  keyrecord_t *record) {
  return true;
}

__attribute__((weak)) layer_state_t
layer_state_set_keymap(layer_state_t state) {
  return state;
}
__attribute__((weak)) void keyboard_post_init_keymap(void) {
  return;
}

// void dynamic_macro_record_start_user(void) { dynamic_macro.recording = true; }
void dynamic_macro_record_start_user(int8_t direction) { dynamic_macro.recording = true; }

void dynamic_macro_record_end_user(int8_t direction) {
  dynamic_macro.recording = false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // #ifdef CONSOLE_ENABLE
  //     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u,
  //     int: %u, count: %u\n", keycode, record->event.key.col,
  //     record->event.key.row, record->event.pressed, record->event.time,
  //     record->tap.interrupted, record->tap.count);
  // #endif

  if (!process_select_word(keycode, record, SELWORD)) {
    return false;
  }

  const uint8_t mods = get_mods();
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

      #ifndef FLASH_BOOTLOADER
        if ((temp_mod | temp_osm) & MOD_MASK_SHIFT)
      #endif
      {
        SEND_STRING("qmk compile -kb " QMK_KEYBOARD " -km " QMK_KEYMAP);
      } else {
        SEND_STRING("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER));
        reset_keyboard();
      }

      if ((temp_mod | temp_osm) & MOD_MASK_CTRL) {
        SEND_STRING(" -j8");
      }
      tap_code(KC_ENT);
      set_mods(temp_mod);
    }
    return false;
  case SEND_RAW_TEST:
    #ifdef RAW_ENABLE
      if (record->event.pressed) {
        uint8_t layer_data[32];
        layer_data[0] = 1;
        layer_data[1] = get_highest_layer(layer_state|default_layer_state);
        raw_hid_send(layer_data, 32);
        // uint8_t data[32];
        // memset(data, 0, 32);
        // data[0] = 'A';
        // data[1] = 'B';
        // data[2] = 'C';
        // raw_hid_send(data, 32);
      }
    #endif
    return false;

    case AP_TNXT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_TAB)));
      }
      return false;
    case AP_TPRV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_TAB))));
      }
      return false;
    case AP_TCLS:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_W)));
      }
      return false;
  }
  return process_record_keymap(keycode, record) &&
         process_record_secrets(keycode, record);
}


layer_state_t layer_state_set_user(layer_state_t state) {
  #ifdef AP_KEYMAP_OVERLAY_ENABLE
    // dprintf("layer_state_set_user: %d\n", state);
      // dprintf("send raw layer: %d\n", get_highest_layer(state));
      // uint8_t data[32];
      // data[2] = get_highest_layer(state);
      // data[2] = 1;
      // raw_hid_send(data, 32);
  #endif

  layer_state_t keymap_state = layer_state_set_keymap(state);
  // #ifdef RAW_ENABLE
  //   uint8_t response[32];
  //   memset(response, 0, 32);
  //   response[0] = get_highest_layer(keymap_state);

  //   // if(data[0] == 'A') {
  //   raw_hid_send(response, 32);
  //   // }
  // #endif

  return keymap_state;
}



void keyboard_post_init_user() {

#ifdef CONSOLE_ENABLE
  debug_config.enable = true;
  // debug_config.keyboard = true;
  // debug_config.matrix = true;
#endif

  keyboard_post_init_keymap();
}

void matrix_scan_user(void) {
  matrix_scan_keymap();
  select_word_task();
}



#ifdef I2C_SCANNER_ENABLE
#    include "i2c_master.h"
#    include "debug.h"

#    ifndef I2C_SCANNER_TIMEOUT
#        define I2C_SCANNER_TIMEOUT 50
#    endif

i2c_status_t i2c_start_bodge(uint8_t address, uint16_t timeout) {
    i2c_start(address);

    // except on ChibiOS where the only way is do do "something"
    uint8_t data = 0;
    return i2c_readReg(address, 0, &data, sizeof(data), I2C_SCANNER_TIMEOUT);
}

#    define i2c_start i2c_start_bodge

void do_scan(void) {
    uint8_t nDevices = 0;

    dprintf("Scanning...\n");

    for (uint8_t address = 1; address < 127; address++) {
        // The i2c_scanner uses the return value of
        // i2c_start to see if a device did acknowledge to the address.
        i2c_status_t error = i2c_start(address << 1, I2C_SCANNER_TIMEOUT);
        if (error == I2C_STATUS_SUCCESS) {
            i2c_stop();
            xprintf("  I2C device found at address 0x%02X\n", I2C_SCANNER_TIMEOUT);
            nDevices++;
        } else {
            // dprintf("  Unknown error (%u) at address 0x%02X\n", error, address);
        }
    }

    if (nDevices == 0)
        xprintf("No I2C devices found\n");
    else
        xprintf("done\n");
}

uint16_t scan_timer = 0;

void housekeeping_task_i2c_scanner(void) {
    if (timer_elapsed(scan_timer) > 5000) {
        do_scan();
        scan_timer = timer_read();
    }
}

void keyboard_post_init_i2c(void) {
    i2c_init();
    scan_timer = timer_read();
}
#endif
