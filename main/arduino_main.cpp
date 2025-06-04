// SPDX-License-Identifier: Apache-2.0
// Copyright 2021 Ricardo Quesada
// http://retro.moe/unijoysticle2

#include "sdkconfig.h"

#include <Arduino.h>
#include <Bluepad32.h>
#include "controller_callbacks.h"

#include "helper/challenges.h"
#include "helper/motors.h"

#include <uni.h>

extern ControllerPtr myControllers[BP32_MAX_GAMEPADS];
// ControllerPtr myCtl = myControllers[0]; // we will only ever have one controller connected, so 0 index will grab the one we need

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

    // SAMPLE CODE BEGIN
    BP32.setup(&onConnectedController, &onDisconnectedController);
    BP32.forgetBluetoothKeys(); // i actually dont know if we want this lol
    esp_log_level_set("gpio", ESP_LOG_ERROR); // suppress info log spam from gpio_isr_service
    uni_bt_allowlist_set_enabled(true); // only allow whitelisted BLE connections
    BP32.enableVirtualDevice(false); // i think virtual device refers to stuff like the "mouse" trackpad thing for PS4 controllers
    esp_log_level_set("gpio", ESP_LOG_ERROR); // suppress info log spam from gpio_isr_service
    esp_log_level_set("BT_L2CAP", ESP_LOG_DEBUG);
    esp_log_level_set("BLUEPAD32", ESP_LOG_DEBUG);
    Console.printf("Free heap: %d\n", esp_get_free_heap_size());
    // SAMPLE CODE END


    
    initMotors();
}

// A -> color
// L1 -> line precalibrated
// L2 -> line uncalibrated
// Y -> distance
// B -> return to idle
void loop() {
    vTaskDelay(1); // ensures WDT does not get triggered when no controller is connected
    BP32.update(); // note you MUST call BP32.update() to read values from the controller into the controller data structures
    // make sure to call this in loops if you expect to read from your controller!!!

    for (auto myCtl : myControllers) { // TODO look into removing this. we will not need to iterate over each controller since we will always have one
    if (myCtl && myCtl->isConnected() && myCtl->hasData()) {  
    // if (myCtl && (myCtl->isConnected() && myCtl->hasData())) {     
        needExit = false; // reset if returning from challenge force exit
        moveMain(myCtl);
        // while(1) {
        //     BP32.update();
        //     dumpGamepad(myCtl);
        //     delay(100);
        // }
        delay(100);

        if(myCtl->a()) {
            Console.println("button a pressed - entering color mode");
            colorChallenge(myCtl);
        }
        else if(myCtl->l1()) {
            Console.println("button l2 pressed - entering precalibrated line mode");
            lineChallenge(myCtl, true);
        }
        else if(myCtl->l2()) {
            Console.println("button l2 pressed - entering uncalibrated line mode");
            lineChallenge(myCtl, false);
        }
        else if(myCtl->y()) {
            Console.println("button y pressed - entering IR mode");
            IRChallenge(myCtl);
        }
    }
    else {
        // Console.println("Controller not connected :(");
        // delay(1000);
    }
}
}