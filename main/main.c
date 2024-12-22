// Example file - Public Domain
// Need help? https://tinyurl.com/bluepad32-help

#include <stdlib.h>

#include <btstack_port_esp32.h>
#include <btstack_run_loop.h>
#include <btstack_stdio_esp32.h>
#include <uni.h>

#include "sdkconfig.h"

// Sanity check
#ifndef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
#error "Must use BLUEPAD32_PLATFORM_CUSTOM"
#endif

// Defined in my_platform.c
struct uni_platform* get_my_platform(void);

void testlogi(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args); // Write formatted output to stdout
    va_end(args);
    fflush(stdout); // Ensure immediate output
}

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
        i++;
        testlogi("Hello, World! %d\n", i);
    }
    // Does not return.
    btstack_run_loop_execute();

    return 0;
}

