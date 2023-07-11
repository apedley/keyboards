#include "qmk_rc.h"
#include "raw_hid.h"
#include "print.h"
#include <stdlib.h>

#ifndef QMK_RC_DISABLE_DEFAULT_COMMANDS
#include "quantum.h"
#include <string.h>
#ifdef OLED_ENABLE
#include "oled_driver.h"
#endif
#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif
#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#endif
#endif

__attribute__((weak)) void
qmk_rc_process_command_user(qmk_rc_command_t *command) {}

enum qmk_rc_commands_quantum {
  RESERVED = 0,
#ifndef QMK_RC_DISABLE_DEFAULT_COMMANDS
  OLED_OFF,
  OLED_ON,
  // OLED_WRITE accepts a string to write to the OLED display.
  OLED_WRITE,
  OLED_CLEAR,

  RGBLIGHT_OFF,
  RGBLIGHT_ON,
  // RGBLIGHT_SETRGB_RANGE and RGB_MATRIX_SETRGB_RANGE accept 5 data bytes:
  // R - G - B - I0 - I1
  // * RGB - the color
  // * I0 - the LED index start
  // * I1 - the LED index end
  RGBLIGHT_SETRGB_RANGE,

  RGB_MATRIX_OFF,
  RGB_MATRIX_ON,
  RGB_MATRIX_SETRGB_RANGE,

  LAYER_ON,
  LAYER_OFF,
  LAYER_CLEAR,
  LAYER_MOVE,

  SEND_STRING,
#endif
  GET_LAYER,
  GET_INFO,
  GET_KEY,
};

#ifdef RGB_MATRIX_ENABLE

#define MY_RGB_MATRIX_SETRGB_RANGE 128
#define MY_RGB_MATRIX_CLEAR 129
#define MY_RGB_MATRIX_SETRGB_ALL 130
#define MY_RGB_MATRIX_GET_MODE 131

my_rgb_range_t my_rgb_range;
#endif
#define MY_GET_KEYMAP_KEY 132

#ifndef QMK_RC_DISABLE_DEFAULT_COMMANDS
void qmk_rc_process_command_quantum(qmk_rc_command_t *command) {

  if (debug_enable) {
      print("qmk_rc_process_command_quantum: ");
      print_hex8(command->id);
      print("\n");
  }
  switch (command->id) {
#ifdef OLED_ENABLE
  case OLED_OFF:
    oled_off();
    break;
  case OLED_ON:
    oled_on();
    break;
  case OLED_WRITE:
    oled_write((const char *)command->data, false);
    break;
  case OLED_CLEAR:
    oled_clear();
    break;
#endif

#ifdef RGBLIGHT_ENABLE
  case RGBLIGHT_OFF:
    rgblight_disable_noeeprom();
    break;
  case RGBLIGHT_ON:
    rgblight_enable_noeeprom();
    break;
  case RGBLIGHT_SETRGB_RANGE:
    dprintf("RGB_SETRGB_RANGE: %d %d %d %d %d\n", command->data[0],
            command->data[1], command->data[2], command->data[3],
            command->data[4]);
    rgblight_setrgb_range(command->data[0], // R
                          command->data[1], // G
                          command->data[2], // B
                          command->data[3], // diode index start
                          command->data[4]  // diode index end
    );
    break;
#endif

#ifdef RGB_MATRIX_ENABLE
  case RGB_MATRIX_OFF:
    rgb_matrix_disable_noeeprom();
    break;
  case RGB_MATRIX_ON:
    rgb_matrix_enable_noeeprom();
    break;
  case RGB_MATRIX_SETRGB_RANGE:
    dprintf("RGB_MATRIX_SETRGB_RANGE: %d %d %d %d %d\n", command->data[0],
            command->data[1], command->data[2], command->data[3],
            command->data[4]);
    for (int i = command->data[3]; i < command->data[4]; i++)
      rgb_matrix_set_color(i, command->data[0], command->data[1],
                           command->data[2]);
    break;
  case MY_RGB_MATRIX_SETRGB_RANGE:
      // uint16_t keycode = dynamic_keymap_get_keycode(command->data[0], command->data[1], command->data[2]);
    dprintf("Got request command: %d\n", command->id);
    for (int i = 0; i < command->data_length; i++) {
      dprintf("%d ", command->data[i]);
    }
    dprintf("\n");
    my_rgb_range.red = command->data[0];
    my_rgb_range.green = command->data[1];
    my_rgb_range.blue = command->data[2];
    my_rgb_range.led_min = command->data[3];
    my_rgb_range.led_max = command->data[4];
    my_rgb_range.is_set = true;
    break;
  case MY_RGB_MATRIX_CLEAR:
    my_rgb_range.red = 0;
    my_rgb_range.green = 0;
    my_rgb_range.blue = 0;
    my_rgb_range.led_min = 0;
    my_rgb_range.led_max = 0;
    my_rgb_range.is_set = false;
    break;
  case MY_RGB_MATRIX_SETRGB_ALL:
    my_rgb_range.red = command->data[0];
    my_rgb_range.green = command->data[1];
    my_rgb_range.blue = command->data[2];
    my_rgb_range.led_min = 1;
    my_rgb_range.led_max = 0;
    my_rgb_range.is_set = true;
    break;
  case MY_RGB_MATRIX_GET_MODE:
    uint8_t matrix_data[32];
    matrix_data[2] = rgb_matrix_get_mode();
    raw_hid_send(matrix_data, 32);
    break;

#endif

  case MY_GET_KEYMAP_KEY:
  for (int i = 0; i < command->data_length; i++) {
      dprintf("%d ", command->data[i]);
    }
    dprintf("\n");
    uint16_t keymap_keycode = keymap_key_to_keycode(command->data[0], (keypos_t) {.row = command->data[1], .col = command->data[2]});
    uint8_t keymap_keycode_data[32];
    memset(keymap_keycode_data, 0, 32);
    keymap_keycode_data[2] = keymap_keycode >> 8;
    keymap_keycode_data[3] = keymap_keycode & 0xFF;
    raw_hid_send(keymap_keycode_data, 32);
    break;

  case LAYER_ON:
    layer_on(command->data[0]);
    break;
  case LAYER_OFF:
    layer_off(command->data[0]);
    break;
  case LAYER_CLEAR:
    layer_clear();
    break;
  case LAYER_MOVE:
    layer_move(command->data[0]);
    break;

  case SEND_STRING:
    send_string((const char *)command->data);
    break;

  case GET_LAYER:
    uint8_t layer_data[32];
    layer_data[2] = get_highest_layer(layer_state|default_layer_state);
    raw_hid_send(layer_data, 32);
    break;

  case GET_INFO:
    uint8_t info_data[32];
    memset(info_data, 0, 32);
    info_data[2] = matrix_rows();
    info_data[3] = matrix_cols();
    info_data[4] = DYNAMIC_KEYMAP_LAYER_COUNT;
    #ifdef SPLIT_KEYBOARD
      info_data[5] = 1;
    #endif
    dprintf("Sending info: %d %d %d %d\n", info_data[2], info_data[3], info_data[4], info_data[5]);
    raw_hid_send(info_data, 32);
    break;

  case GET_KEY:
    // uint16_t keycode = dynamic_keymap_get_keycode(command->data[0], command->data[1], command->data[2]);
    dprintf("Got request command: %d\n", command->id);
    for (int i = 0; i < command->data_length; i++) {
      dprintf("%d ", command->data[i]);
    }
    dprintf("\n");
    uint16_t keycode = keymap_key_to_keycode(command->data[0], (keypos_t) {.row = command->data[1], .col = command->data[2]});
    // dprintf("Got keycode: %d\n", keycode);
    uint8_t key_data[32];
    memset(key_data, 0, 32);
    key_data[2] = keycode >> 8;
    key_data[3] = keycode & 0xFF;
    raw_hid_send(key_data, 32);
    break;

  default:
    qmk_rc_process_command_user(command);
  }
}
#else
#define qmk_rc_process_command_quantum qmk_rc_process_command_user
#endif

qmk_rc_parser_t parser = {
    .state = RECEIVING_COMMAND,
    .data_bytes_read = 0,
};

qmk_rc_command_t command = {
    .id = UINT8_MAX,
    .data_length = 0,
    .data = NULL,
};

void qmk_rc_receive(uint8_t *buffer, uint16_t max_buffer_length, uint8_t *data,
                    uint8_t data_length) {
  for (int i = 0; i < data_length; i++) {
    if (parser.state == RECEIVING_COMMAND) {
      // Raw HID packets are padded to `RAW_EPSIZE`, 32 or 64 bytes. Since this
      // is an afterthought for this parser, we reserve the 0 command code as
      // a "skip" instruction in receiving command mode. In the sender we then
      // universally pad to 64 bytes with 0s.
      if (data[i] == 0)
        continue;

      command.id = data[i];
      parser.state = RECEIVING_DATA_LENGTH;

      parser.data_length_bytes_read = 0;
      parser.data_length.data_length = 0;
    } else if (parser.state == RECEIVING_DATA_LENGTH) {
      parser.data_length.raw[parser.data_length_bytes_read++] = data[i];

      if (parser.data_length_bytes_read == sizeof(qmk_rc_data_length_t)) {
        command.data_length = parser.data_length.data_length;

        command.data = NULL;

        if (command.data_length == 0) {
          qmk_rc_process_command_quantum(&command);
          parser.state = RECEIVING_COMMAND;
        } else {
          parser.state = RECEIVING_DATA;
          parser.data_bytes_read = 0;
        }
      }
    } else if (parser.state == RECEIVING_DATA) {
      buffer[parser.data_bytes_read++] = data[i];
      if (parser.data_bytes_read == command.data_length) {
        command.data = buffer;
        qmk_rc_process_command_quantum(&command);
        parser.state = RECEIVING_COMMAND;
      }
    }
  }
}
