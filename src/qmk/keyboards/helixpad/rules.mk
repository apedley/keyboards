
ifeq ($(strip $(OLED_ENABLE)), yes)
	OLED_ENABLE = yes
	OLED_DRIVER = SSD1306
  SRC += oled_display.c
endif



RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = vendor

EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes

CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes

BOOTMAGIC_ENABLE = yes
RAW_ENABLE = no
