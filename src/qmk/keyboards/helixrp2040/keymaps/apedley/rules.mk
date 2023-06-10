

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += oled_display.c
endif
WPM_ENABLE = yes

CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes

RAW_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes

COMBO_ENABLE = yes

MOUSEKEY_ENABLE = yes

REPEAT_KEY_ENABLE = yes
