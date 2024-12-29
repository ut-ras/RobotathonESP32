#include <stdio.h>
#include "esp_err.h"
#include "driver/i2c.h"
#include "esp_log.h"

#define I2C_PORT_NUM I2C_NUM_0
#define I2C_MASTER_SCL_IO 22
#define I2C_MASTER_SDA_IO 21
#define I2C_FREQ_HZ 100000
#define APDS9960_I2C_ADDR 0x39

#define APDS9960_ENABLE 0x80
#define APDS9960_ATIME 0x81
#define APDS9960_CONTROL 0x8F
#define APDS9960_CDATAL 0x94
#define APDS9960_CDATAH 0x95
#define APDS9960_RDATAL 0x96
#define APDS9960_RDATAH 0x97
#define APDS9960_GDATAL 0x98
#define APDS9960_GDATAH 0x99
#define APDS9960_BDATAL 0x9A
#define APDS9960_BDATAH 0x9B

enum
{
    RED,
    GREEN,
    BLUE
};

void i2c_master_init();
esp_err_t apds9960_write_byte(uint8_t reg, uint8_t data);
esp_err_t apds9960_read_bytes(uint8_t reg, uint8_t *data, size_t len);
void apds9960_init();
uint16_t apds9960_read_color(uint8_t low_reg, uint8_t high_reg);
int getMaxColor(int red, int green, int blue);
