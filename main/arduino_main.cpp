// SPDX-License-Identifier: Apache-2.0
// Copyright 2021 Ricardo Quesada
// http://retro.moe/unijoysticle2

#include "sdkconfig.h"

#include <Arduino.h>
#include <Bluepad32.h>
#include "controller_callbacks.h"

#include "helper/challenges.h"
#include "helper/motors.h"

extern ControllerPtr myControllers[BP32_MAX_GAMEPADS];

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

void setup() {
    BP32.setup(&onConnectedController, &onDisconnectedController);
    BP32.forgetBluetoothKeys(); 
    esp_log_level_set("gpio", ESP_LOG_ERROR); // suppress info log spam from gpio_isr_service
}

// A -> color
// B -> return to idle
// X -> line
// Y -> distance
void loop() {
    vTaskDelay(1); // ensures WDT does not get triggered when no controller is connected
    BP32.update(); 
    for (auto myController : myControllers) {
        if (myController && myController->isConnected() && myController->hasData()) {        

            moveMain(myController);
            // while(1) {
            //     BP32.update();
            //     dumpGamepad(myController);
            //     delay(100);
            // }
            // testNVS();
            delay(100);

            if(myController->a()) {
                Console.print("button a pressed - entering color mode\n");
                colorChallenge(myController);
            }
            else if(myController->x()) {
                Console.print("button x pressed - entering line mode\n");
                lineChallenge(myController);
            }
            else if(myController->y()) {
                Console.print("button y pressed - entering IR mode");
                IRChallenge(myController);
            }
        }
    }
}