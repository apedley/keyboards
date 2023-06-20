CONSOLE_ENABLE = yes
RGB_MATRIX_ENABLE = yes
AUDIO_ENABLE =yes
ENCODER_ENABLE = yes
HAPTIC_ENABLE = yes


FP_CIRQUE_LEFT_ONLY = yes

# CIRQUE_ENABLE = yes

OLED_ENABLE = no

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += oled_display.c
	OLED_DRIVER = SSD1306
	WPM_ENABLE = yes
endif

# POINTING_DEVICE_ENABLE = yes
# POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
# POINTING_DEVICE_DRIVER = pimoroni_trackball

# QUANTUM_PAINTER_ENABLE = yes
# QUANTUM_PAINTER_DRIVERS += gc9a01_spi
QUANTUM_PAINTER_ENABLE = yes
ifeq ($(strip $(QUANTUM_PAINTER_ENABLE)), yes)
  SRC += lcd_display.c
	WPM_ENABLE = yes
	QUANTUM_PAINTER_LVGL_INTEGRATION = yes
	QUANTUM_PAINTER_DRIVERS = gc9a01_spi
endif