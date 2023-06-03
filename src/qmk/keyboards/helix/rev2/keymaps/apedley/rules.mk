SPLIT_KEYBOARD = yes

LTO_ENABLE = yes  # if firmware size over limit, try this option

# Helix Spacific Build Options
# you can uncomment and edit follows 7 Variables
#  jp: 以下の7つの変数を必要に応じて編集し、コメントアウトをはずします。
HELIX_ROWS = 5              # Helix Rows is 4 or 5
OLED_ENABLE = yes            # OLED_ENABLE
LOCAL_GLCDFONT = yes         # use each keymaps "helixfont.h" insted of "common/glcdfont.c"
RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.
LED_BACK_ENABLE = yes        # LED backlight (Enable WS2812 RGB underlight.)
LED_UNDERGLOW_ENABLE = yes   # LED underglow (Enable WS2812 RGB underlight.)
LED_ANIMATIONS = yes         # LED animations
# IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)

# OLED_ENABLE が yes のとき
#   OLED_SELECT が core ならば QMK 標準の oled_dirver.c を使用します。
#   OLED_SELECT が core 以外ならば従来どおり helix/local_drivers/ssd1306.c を使用します。
# If OLED_ENABLE is 'yes'
#   If OLED_SELECT is 'core', use QMK standard oled_dirver.c.
#   If OLED_SELECT is other than 'core', use helix/local_drivers/ssd1306.c.
OLED_SELECT = core


ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += oled_display.c
endif

BONGO_ENABLE = yes
WPM_ENABLE = yes

BOOTLOADER = rp2040
CONVERT_TO = promicro_rp2040

CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes

RAW_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes

CAPS_WORD_ENABLE = yes

MOUSEKEY_ENABLE = yes

OPT_DEFS += -DRGBLED_BACK
