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

static const char *TAG = "APDS9960";

void i2c_master_init() {
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_FREQ_HZ,
    };
    ESP_ERROR_CHECK(i2c_param_config(I2C_PORT_NUM, &conf));
    ESP_ERROR_CHECK(i2c_driver_install(I2C_PORT_NUM, conf.mode, 0, 0, 0));
}

esp_err_t apds9960_write_byte(uint8_t reg, uint8_t data) {
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (APDS9960_I2C_ADDR << 1) | I2C_MASTER_WRITE, true);
    i2c_master_write_byte(cmd, reg, true);
    i2c_master_write_byte(cmd, data, true);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(I2C_PORT_NUM, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);
    return ret;
}

esp_err_t apds9960_read_bytes(uint8_t reg, uint8_t *data, size_t len) {
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (APDS9960_I2C_ADDR << 1) | I2C_MASTER_WRITE, true);
    i2c_master_write_byte(cmd, reg, true);
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (APDS9960_I2C_ADDR << 1) | I2C_MASTER_READ, true);
    i2c_master_read(cmd, data, len, I2C_MASTER_LAST_NACK);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(I2C_PORT_NUM, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);
    return ret;
}

void apds9960_init() {
    ESP_ERROR_CHECK(apds9960_write_byte(APDS9960_ENABLE, 0x03)); // Power on and enable ADC
    ESP_ERROR_CHECK(apds9960_write_byte(APDS9960_ATIME, 0xFF));  // Set ADC integration time
    ESP_ERROR_CHECK(apds9960_write_byte(APDS9960_CONTROL, 0x01)); // Set gain
}

uint16_t apds9960_read_color(uint8_t low_reg, uint8_t high_reg) {
    uint8_t low, high;
    ESP_ERROR_CHECK(apds9960_read_bytes(low_reg, &low, 1));
    ESP_ERROR_CHECK(apds9960_read_bytes(high_reg, &high, 1));
    return ((uint16_t)high << 8) | low;
}

int getMaxColor(int red, int green, int blue) {
    int color = 0;
    if(red > 0) color = 0;
    if(green > x) color = 1;
    if(blue > y) color = 2;
    return color;
}


void app_main(void) {
    i2c_master_init();
    apds9960_init();

    gpio_set_direction(GPIO_NUM_36, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_39, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_34, GPIO_MODE_OUTPUT);


    while (1) {
        uint16_t clear = apds9960_read_color(APDS9960_CDATAL, APDS9960_CDATAH);
        uint16_t red = apds9960_read_color(APDS9960_RDATAL, APDS9960_RDATAH);
        uint16_t green = apds9960_read_color(APDS9960_GDATAL, APDS9960_GDATAH);
        uint16_t blue = apds9960_read_color(APDS9960_BDATAL, APDS9960_BDATAH);

        ESP_LOGI(TAG, "Clear: %d, Red: %d, Green: %d, Blue: %d", clear, red, green, blue);
        
        switch(getMaxColor(red, green, blue)) {
            case(RED) {
                gpio_set_level(GPIO_NUM_36, 1);
                gpio_set_level(GPIO_NUM_39, 0);
                gpio_set_level(GPIO_NUM_34, 0);
                break;
            }
            case(GREEN) {
                gpio_set_level(GPIO_NUM_36, 0);
                gpio_set_level(GPIO_NUM_39, 1);
                gpio_set_level(GPIO_NUM_34, 0);
                break;
            }
            case(BLUE) {
                gpio_set_level(GPIO_NUM_36, 1);
                gpio_set_level(GPIO_NUM_39, 0);
                gpio_set_level(GPIO_NUM_34, 0);
                break;
            }
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}