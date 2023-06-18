CONSOLE_ENABLE = yes
RGB_MATRIX_ENABLE = yes
AUDIO_ENABLE =yes
ENCODER_ENABLE = yes
HAPTIC_ENABLE = yes

OLED_ENABLE = no

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += oled_display.c
	OLED_DRIVER = SSD1306
	WPM_ENABLE = yes
endif

# POINTING_DEVICE_ENABLE = yes
# POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
# POINTING_DEVICE_DRIVER = pimoroni_trackball

