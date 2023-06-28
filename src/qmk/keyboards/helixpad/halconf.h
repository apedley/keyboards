#pragma once

#ifdef OLED_ENABLE
  #define HAL_USE_I2C TRUE
#endif // OLED_ENABLE


#ifdef POINTING_DEVICE_ENABLE
  #define HAL_USE_I2C TRUE
#endif // POINTING_DEVICE_ENABLE
#include_next <halconf.h>
