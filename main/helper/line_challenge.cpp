#include "challenges.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"


QTRSensors qtr;
uint16_t sensors[2];
bool lineIsCalibrated = false;

void testNVS() {
    // Initialize NVS
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        // NVS partition was truncated and needs to be erased
        // Retry nvs_flash_init
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK( err );

    // Open
    printf("\n");
    printf("Opening Non-Volatile Storage (NVS) handle... ");
    nvs_handle_t my_handle;
    err = nvs_open("storage", NVS_READWRITE, &my_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {
        printf("Done\n");

        // Read
        printf("Reading restart counter from NVS ... ");
        int32_t restart_counter = 0; // value will default to 0, if not set yet in NVS
        err = nvs_get_i32(my_handle, "restart_counter", &restart_counter);
        switch (err) {
            case ESP_OK:
                printf("Done\n");
                printf("Restart counter = %" PRIu32 "\n", restart_counter);
                break;
            case ESP_ERR_NVS_NOT_FOUND:
                printf("The value is not initialized yet!\n");
                break;
            default :
                printf("Error (%s) reading!\n", esp_err_to_name(err));
        }

        // Write
        printf("Updating restart counter in NVS ... ");
        restart_counter++;
        err = nvs_set_i32(my_handle, "restart_counter", restart_counter);
        printf((err != ESP_OK) ? "Failed!\n" : "Done\n");

        // Commit written value.
        // After setting any values, nvs_commit() must be called to ensure changes are written
        // to flash storage. Implementations may write to storage at other times,
        // but this is not guaranteed.
        printf("Committing updates in NVS ... ");
        err = nvs_commit(my_handle);
        printf((err != ESP_OK) ? "Failed!\n" : "Done\n");

        // Close
        nvs_close(my_handle);
    }
}


void restoreSensorCalibration() {

}
void lineChallenge(ControllerPtr myController) {
    qtr.setTypeAnalog();

    const uint8_t pins[] = {33, 32};
    const uint8_t numPins = 2;
    qtr.setSensorPins(pins, numPins);
    if(!lineIsCalibrated) {
        for (uint8_t i = 0; i < 250; i++) { 
            Console.println("calibrating");
            qtr.calibrate(); 
            delay(20);
        }
        // qtr.saveCalibratedValues(); // todo: implement this
    }
    while(1) {
        BP32.update();
        qtr.readLineBlack(sensors); // Get calibrated sensor values returned in the sensors array
        Console.printf("S1: %d S2: %d\n", sensors[0], sensors[1]);
        delay(50);
        if(myController->b()) {
            Console.println("button b pressed - exiting to main");
            break;
        }
    }   
}
