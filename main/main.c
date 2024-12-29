#include <stdio.h>
#include "esp_err.h"
#include "driver/i2c.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "apds9960.h"

void app_main(void) {
    i2c_master_init();
    apds9960_init();

    gpio_set_direction(GPIO_NUM_12, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_14, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_27, GPIO_MODE_OUTPUT);

    static const char *TAG = "APDS9960";

    while (1) {
        uint16_t clear = apds9960_read_color(APDS9960_CDATAL, APDS9960_CDATAH);
        uint16_t red = apds9960_read_color(APDS9960_RDATAL, APDS9960_RDATAH);
        uint16_t green = apds9960_read_color(APDS9960_GDATAL, APDS9960_GDATAH);
        uint16_t blue = apds9960_read_color(APDS9960_BDATAL, APDS9960_BDATAH);

        ESP_LOGI(TAG, "Clear: %d, Red: %d, Green: %d, Blue: %d", clear, red, green, blue);
        
        switch(getMaxColor(red, green, blue)) {
            case(RED):
                gpio_set_level(GPIO_NUM_12, 1);
                gpio_set_level(GPIO_NUM_14, 0);
                gpio_set_level(GPIO_NUM_27, 0);
                break;
            case(GREEN):
                gpio_set_level(GPIO_NUM_12, 0);
                gpio_set_level(GPIO_NUM_14, 1);
                gpio_set_level(GPIO_NUM_27, 0);
                break;
            case(BLUE):
                gpio_set_level(GPIO_NUM_12, 0);
                gpio_set_level(GPIO_NUM_14, 0);
                gpio_set_level(GPIO_NUM_27, 1);
                break;
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}