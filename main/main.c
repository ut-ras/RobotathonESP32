#include <stdio.h>
#include <stdlib.h>
#include "esp_err.h"
#include "driver/i2c.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

#include <btstack_port_esp32.h>
#include <btstack_run_loop.h>
#include <btstack_stdio_esp32.h>
#include <uni.h>
// #include "btstack_run_loop_embedded.h"


#include "apds9960.h"

#ifndef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
#error "Must use BLUEPAD32_PLATFORM_CUSTOM"
#endif

struct uni_platform* get_my_platform(void);

void app_main(void) {

    btstack_init();
    uni_platform_set_custom(get_my_platform());
    uni_init(0 /* argc */, NULL /* argv */);

    i2c_master_init();
    apds9960_init();

    gpio_set_direction(GPIO_NUM_12, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_14, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_27, GPIO_MODE_OUTPUT);

    static const char *TAG = "APDS9960";
    bd_addr_t addr = {0x98, 0xb6, 0x0F, 0x36, 0x36, 0x21};
    uni_bt_allowlist_add_addr(addr);
    uni_bt_allowlist_set_enabled(true);
    btstack_run_loop_execute(); //does not return

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

        if(0) { // TODO: if bp32 controller has input on X 
            break;
            // btstack_run_loop_execute_on_main_thread();
            // btstack_run_loop_execute_on_main_thread();
            // btstack_run_loop_execute();
            // ESP_LOGI("breaking!!!!\n");
        }
    }
}