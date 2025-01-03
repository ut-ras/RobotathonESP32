// SPDX-License-Identifier: Apache-2.0
// Copyright 2021 Ricardo Quesada
// http://retro.moe/unijoysticle2

#include "sdkconfig.h"

#include <Arduino.h>
#include <Bluepad32.h>
#include "controller_callbacks.h"

#include "challenges.h"

extern ControllerPtr myControllers[BP32_MAX_GAMEPADS];

QTRSensors qtr;
uint16_t sensors[2];

ESP32SharpIR IRSensorName(ESP32SharpIR::GP2Y0A21YK0F, 12);

void dumpGamepad(ControllerPtr ctl) {
    Console.printf(
        "DPAD: %d A: %d B: %d X: %d Y: %d LX: %d LY: %d RX: %d RY: %d L1: %d R1: %d L2: %d R2: %d\n",
        ctl->dpad(),         // D-pad
        ctl->a(), 
        ctl->b(),
        ctl->x(),
        ctl->y(),
        ctl->axisX(),        // (-511 - 512) left X Axis
        ctl->axisY(),        // (-511 - 512) left Y axis
        ctl->axisRX(),       // (-511 - 512) right X axis
        ctl->axisRY(),       // (-511 - 512) right Y axis
        ctl->l1(),
        ctl->r1(),
        ctl->l2(),
        ctl->r2()
    );
}

// Arduino setup function. Runs in CPU 1
void setup() {
    BP32.setup(&onConnectedController, &onDisconnectedController);
    BP32.forgetBluetoothKeys(); 
    esp_log_level_set("gpio", ESP_LOG_ERROR); // suppress info log spam from gpio_isr_service
}

// Arduino loop function. Runs in CPU 1.
void loop() {
    vTaskDelay(1); // ensures WDT does not get triggered when no controller is connected
    BP32.update(); 
    for (auto myController : myControllers) {
        if (myController && myController->isConnected() && myController->hasData()) {        

            Console.print("Idle\n");
            // while(1) {
            //     BP32.update();
            //     dumpGamepad(myController);
            //     delay(100);
            // }

            if(myController->a()) {
                Console.print("button a pressed - entering color mode\n");
                colorChallenge(myController);
                // colorChallenge();  
            }
            else if(myController->x()) {
                Console.print("button x pressed - entering line mode\n");
                qtr.setTypeAnalog(); // or setTypeAnalog()

                const uint8_t pins[] = {33, 32};
                const uint8_t numPins = 2;
                qtr.setSensorPins(pins, numPins);
                for (uint8_t i = 0; i < 250; i++) { 
                    Console.println("calibrating");
                    qtr.calibrate(); 
                    delay(20);
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
            else if(myController->y()) {
                Console.print("button y pressed - entering IR mode");
                IRSensorName.setFilterRate(1.0f);
                float distance;
                while(1) {
                    BP32.update();
                    distance = IRSensorName.getDistanceFloat();
                    Console.println(distance); 
                    if(myController->b()) {
                        Console.println("button b pressed - exiting to main");
                        break;
                    }
                }   
            }
        }
    }
}