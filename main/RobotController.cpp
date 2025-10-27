#include "sdkconfig.h"
#include <Arduino.h>
#include <Bluepad32.h>
#include <uni.h>
#include "controller_callbacks.h"

#include "Drivetrain.cpp"
#include "LineSensor.cpp"
#include "LineFollow.cpp"
#include "Routine.cpp"

#define IN1  16  // Control pin 1
#define IN2  17  // Control pin 2
#define IN3  18  // Control pin 3
#define IN4  19  // Control pin 4

#define OUT1 32
#define OUT2 33
#define OUT3 34
#define OUT4 35

#define LED 2

Drivetrain drivetrain(IN1, IN2, IN3, IN4);
LineSensor lineSensor;

Routine* routine;

extern ControllerPtr myControllers[BP32_MAX_GAMEPADS]; // BP32 library allows for up to 4 concurrent controller connections, but we only need 1

void handleController(ControllerPtr myController) {
    
    // Simple direction control - no braking, no state tracking
    if (myController->r2() && !myController->l2()) {  // ZR button for forward
        drivetrain.setSpeed(255, 255);
    } 
    else if (myController->l2() && !myController->r2()) {  // ZL button for backward
        drivetrain.setSpeed(-255, -255);
    }
    else {  // If neither trigger is pressed, or both are pressed, stop the motor
        digitalWrite(LED, LOW); // writes a digital low to pin 2
        drivetrain.setSpeed(0, 0);
    }

    if(myController->dpad() & DPAD_DOWN){
        routine = new LineFollow(&lineSensor, &drivetrain);
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
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    pinMode(LED, OUTPUT);

    pinMode(OUT1, OUTPUT);
    pinMode(OUT2, OUTPUT);
    pinMode(OUT3, OUTPUT);
    pinMode(OUT4, OUTPUT);
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

    if(routine != nullptr){
        routine->update();
    }
    
    vTaskDelay(1); // Small delay to prevent watchdog issues
}
