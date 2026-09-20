#pragma once

// Map display SDA/SCL to your unused physical pins D4 and D5 and define size of the display
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7
#define OLED_DISPLAY_128X32

// Route data via Driver 2 (which operates the RP2040's hardware I2C1 block)
#define I2C_DRIVER I2CD1
