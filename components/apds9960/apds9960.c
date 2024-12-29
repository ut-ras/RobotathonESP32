#include "apds9960.h"

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
    int color = RED;
    if(green > red) color = GREEN;
    if(blue > green) color = BLUE;
    if(blue > red) color = BLUE;
    return color;
}
