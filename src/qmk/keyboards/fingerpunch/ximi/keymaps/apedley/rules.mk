CONSOLE_ENABLE = yes
RGB_MATRIX_ENABLE = yes
AUDIO_ENABLE =yes
ENCODER_ENABLE = yes
HAPTIC_ENABLE = yes
WPM_ENABLE = yes



OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += oled_display.c
endif

