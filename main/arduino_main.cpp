#include "sdkconfig.h"
#include <Arduino.h>
#include <Bluepad32.h>
#include <uni.h>
#include "controller_callbacks.h"

#define IN1  16  // Control pin 1
#define IN2  17  // Control pin 2

extern ControllerPtr myControllers[BP32_MAX_GAMEPADS]; // BP32 library allows for up to 4 concurrent controller connections, but we only need 1

void handleController(ControllerPtr myController) {
    // Simple direction control - no braking, no state tracking
    if (myController->r2() && !myController->l2()) {  // ZR button for forward
        analogWrite(IN1, 255);  // Full speed forward
        digitalWrite(IN2, LOW);
    } 
    else if (myController->l2() && !myController->r2()) {  // ZL button for backward
        digitalWrite(IN1, LOW);
        analogWrite(IN2, 255);  // Full speed backward
    }
    else {  // If neither trigger is pressed, or both are pressed, stop the motor
        analogWrite(IN1, 0);
        analogWrite(IN2, 0);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
    }
}

void setup() {
    Serial.begin(115200);
    uni_bt_allowlist_set_enabled(true); // Enable allowlist first
    BP32.setup(&onConnectedController, &onDisconnectedController);
    esp_log_level_set("gpio", ESP_LOG_ERROR); // Suppress info log spam from gpio_isr_service
    Serial.begin(115200);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
}

void loop() {
    static unsigned long lastDebugTime = 0;
    
    BP32.update(); // Update the gamepad state
    
    // Print debug info every 5 seconds if no controller is connected
    unsigned long currentTime = millis();
    if (currentTime - lastDebugTime >= 5000) {
        bool anyConnected = false;
        for (auto myController : myControllers) {
            if (myController && myController->isConnected()) {
                anyConnected = true;
                Serial.printf("Controller connected - Battery: %d%%\n", myController->battery());
            }
        }
        if (!anyConnected) {
            Serial.println("Waiting for controller connection...");
        }
        lastDebugTime = currentTime;
    }
    
    // Handle connected controllers
    for (auto myController : myControllers) {
        if (myController && myController->isConnected() && myController->hasData()) {
            handleController(myController);
        }
    }
    
    vTaskDelay(1); // Small delay to prevent watchdog issues
}