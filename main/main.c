// Example file - Public Domain
// Need help? https://tinyurl.com/bluepad32-help

#include <stdlib.h>

#include <btstack_port_esp32.h>
#include <btstack_run_loop.h>
#include <btstack_stdio_esp32.h>
#include <uni.h>
#include "sdkconfig.h"
#include "apds9960.h"

// Sanity check
#ifndef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
#error "Must use BLUEPAD32_PLATFORM_CUSTOM"
#endif

// Defined in my_platform.c
struct uni_platform* get_my_platform(void);

// NOT part of sample ========================================
#include "freertos/FreeRTOS.h" 
#include "freertos/task.h" 
#include "apds9960.h" //https://github.com/espressif/esp-iot-solution/tree/23c164ec7f748957e41c2f39a6ed9a6d4b4af56a/components/sensors/gesture/apds9960
// #include "iot_servo.h" // https://github.com/espressif/esp-iot-solution/tree/f5ca5b553873e8ff3c044d5bae56d0eae1d0673b/components/motor/servo


// qtr line sensor 
// GP2Y0A21YK0F sharp IR distance sensor


// color sensor init
// initColorSensor() {
//     i2c_bus_handle_t i2c_bus = NULL;
//     apds9960_handle_t apds9960 = NULL;

//     //Step1: Init I2C bus and VL io
    // gpio_config_t cfg;
//     cfg.pin_bit_mask = BIT(APDS9960_VL_IO);
//     cfg.intr_type = 0;
//     cfg.mode = GPIO_MODE_OUTPUT;
//     cfg.pull_down_en = 0;
//     cfg.pull_up_en = 0;
//     gpio_config(&cfg);
//     gpio_set_level(APDS9960_VL_IO, 0);

//     int i2c_master_port = APDS9960_I2C_MASTER_NUM;
//     i2c_config_t conf = {
//         .mode = I2C_MODE_MASTER,
//         .sda_io_num = APDS9960_I2C_MASTER_SDA_IO,
//         .sda_pullup_en = GPIO_PULLUP_ENABLE,
//         .scl_io_num = APDS9960_I2C_MASTER_SCL_IO,
//         .scl_pullup_en = GPIO_PULLUP_ENABLE,
//         .master.clk_speed = APDS9960_I2C_MASTER_FREQ_HZ,
//     };
// i2c_bus = i2c_bus_create(i2c_master_port, &conf);

// //Step2: Init apds9960
// apds9960 = apds9960_create(i2c_bus, APDS9960_I2C_ADDRESS);

// //Step3: Read gesture
// uint8_t gesture = apds9960_read_gesture(apds9960);
// }


void serialPrint(const char *format, ...){ // implementation is probably bad lol
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args); // Write formatted output to stdout
    va_end(args);
    fflush(stdout); // Ensure immediate output
}

void delay(int ms) {
    vTaskDelay(ms / portTICK_PERIOD_MS);
}


// make controller data a global variable and have them access it asynchrnously(?)


int app_main(void) {
    // hci_dump_open(NULL, HCI_DUMP_STDOUT);

    // Don't use BTstack buffered UART. It conflicts with the console.
#ifdef CONFIG_ESP_CONSOLE_UART
#ifndef CONFIG_BLUEPAD32_USB_CONSOLE_ENABLE
    btstack_stdio_init();
#endif  // CONFIG_BLUEPAD32_USB_CONSOLE_ENABLE
#endif  // CONFIG_ESP_CONSOLE_UART

    // Configure BTstack for ESP32 VHCI Controller
    btstack_init();

    // hci_dump_init(hci_dump_embedded_stdout_get_instance());

    // Must be called before uni_init()
    uni_platform_set_custom(get_my_platform());

    // Init Bluepad32.
    uni_init(0 /* argc */, NULL /* argv */);

    // enable whitelisted connections only
    bd_addr_t addr = {0x98, 0xb6, 0x0F, 0x36, 0x36, 0x21};
    uni_bt_allowlist_add_addr(addr);
    uni_bt_allowlist_set_enabled(true);
    int i = 0;
    while(1) {
        func();
        i++;
        serialPrint("Hello, World! %d\n", i);
        logi("fuck"); // not sure how the buffers of logi is interacting with my serialPrint
    }
    // Does not return.
    btstack_run_loop_execute();

    return 0;
}
