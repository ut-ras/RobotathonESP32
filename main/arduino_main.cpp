// SPDX-License-Identifier: Apache-2.0
// Copyright 2021 Ricardo Quesada
// http://retro.moe/unijoysticle2

#include "sdkconfig.h"
#include <Arduino.h>
#include <Bluepad32.h>
#include <uni.h>
#include "controller_callbacks.h"

#include <ESP32Servo.h>
Servo myServo;

//motor
#define IN1  16  // Control pin 1
#define IN2  17  // Control pin 2
//motor end

#define ONBOARD_LED_PIN 2
extern ControllerPtr myControllers[BP32_MAX_GAMEPADS]; // BP32 library allows for up to 4 concurrent controller connections, but we only need 1

void dumpGamepad(ControllerPtr ctl) {
    Console.printf(
        "DPAD: %d A: %d B: %d X: %d Y: %d LX: %d LY: %d RX: %d RY: %d L1: %d R1: %d L2: %d R2: %d\n",
        ctl->dpad(),        // D-pad
        ctl->a(),           // Letter buttons
        ctl->b(),
        ctl->x(),
        ctl->y(),
        ctl->axisX(),        // (-511 - 512) left X Axis
        ctl->axisY(),        // (-511 - 512) left Y axis
        ctl->axisRX(),       // (-511 - 512) right X axis
        ctl->axisRY(),       // (-511 - 512) right Y axis
        ctl->l1(),           // Bumpers
        ctl->r1(),
        ctl->l2(),
        ctl->r2()
    );
}

void setup() {
    pinMode(ONBOARD_LED_PIN, OUTPUT); // configures pin 2 to be a GPIO output pin 
    BP32.setup(&onConnectedController, &onDisconnectedController);
    BP32.forgetBluetoothKeys(); 
    esp_log_level_set("gpio", ESP_LOG_ERROR); // Suppress info log spam from gpio_isr_service
    uni_bt_allowlist_set_enabled(true);
    myServo.attach(12);
    //motor
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    //motor end 
    Serial.begin(115200);

}

void loop() {
    
    BP32.update(); 
    for (auto myController : myControllers) { // Only execute code when controller is connected
        if (myController && myController->isConnected() && myController->hasData()) {        
            /*
            delay(1000); // waits for 1000 milliseconds (1 second)
            digitalWrite(ONBOARD_LED_PIN, LOW); // writes a digital low to pin 2
            delay(1000);
            */

            //dumpGamepad(myController); // Prints the gamepad state, delete or comment if don't need
            
            /*
            // Spin motor
            digitalWrite(IN1, HIGH);  // PWM signal
            digitalWrite(IN2, LOW); // Direction control

            delay(1000);  // Run for 1 second

            // Stop motor
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);

            delay(1000); // Stop for 1 second
            */

            if (myController->r2()) {
                digitalWrite(IN1, LOW);  // PWM signal
                digitalWrite(IN2, HIGH); // Direction control
                //Move motor when L2 is pressed
            } else if (myController->l2()) {
                digitalWrite(IN1, HIGH);  // PWM signal
                digitalWrite(IN2, LOW); 
                //Move motor when L2 is pressed
            } else {
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                // Stop motor when L2 is released
            }

            vTaskDelay(1); // Yield CPU to not starve other ESP32 processes and cause WDT reset
        }
    }
    
}
