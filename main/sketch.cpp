// SPDX-License-Identifier: Apache-2.0
// Copyright 2021 Ricardo Quesada
// http://retro.moe/unijoysticle2

#include "sdkconfig.h"

#include <Arduino.h>
#include <Bluepad32.h>

#include <Arduino_APDS9960.h>
#include <Wire.h>

#include <QTRSensors.h>

#include <ESP32Servo.h>
#include <QTRSensors.h>
#include <ESP32SharpIR.h>

#define APDS9960_INT 2
#define I2C_SDA 21
#define I2C_SCL 22
#define I2C_FREQ 100000

ControllerPtr myControllers[BP32_MAX_GAMEPADS];

TwoWire I2C_0 = TwoWire(0);
APDS9960 apds = APDS9960(I2C_0, APDS9960_INT);

QTRSensors qtr;
uint16_t sensors[2];

ESP32SharpIR IRSensorName(ESP32SharpIR::GP2Y0A21YK0F, 12);

// This callback gets called any time a new gamepad is connected.
// Up to 4 gamepads can be connected at the same time.
void onConnectedController(ControllerPtr ctl) {
    bool foundEmptySlot = false;
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == nullptr) {
            Console.printf("CALLBACK: Controller is connected, index=%d\n", i);
            // Additionally, you can get certain gamepad properties like:
            // Model, VID, PID, BTAddr, flags, etc.
            ControllerProperties properties = ctl->getProperties();
            Console.printf("Controller model: %s, VID=0x%04x, PID=0x%04x\n", ctl->getModelName(), properties.vendor_id,
                           properties.product_id);
            myControllers[i] = ctl;
            foundEmptySlot = true;
            break;
        }
    }
    if (!foundEmptySlot) {
        Console.println("CALLBACK: Controller connected, but could not found empty slot");
    }
}

void onDisconnectedController(ControllerPtr ctl) {
    bool foundController = false;

    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == ctl) {
            Console.printf("CALLBACK: Controller disconnected from index=%d\n", i);
            myControllers[i] = nullptr;
            foundController = true;
            break;
        }
    }

    if (!foundController) {
        Console.println("CALLBACK: Controller disconnected, but not found in myControllers");
    }
}

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
                int r, g, b, a;
                //sets up color sensor
                I2C_0.begin(I2C_SDA, I2C_SCL, I2C_FREQ);
                // apds.setInterruptPin(APDS9960_INT); // do we need this?
                apds.begin();
                while(1) {
                    BP32.update();
                    // Wait until color is read from the sensor 
                    int watchDogAtHome = 0;
                    while (!apds.colorAvailable()) { 
                        delay(5);
                        watchDogAtHome++;
                        if(watchDogAtHome > 1000) {
                            Console.println("Color sensor broken lmao\n");
                            break;
                        }
                    }
                    apds.readColor(r, g, b, a);
                    // Read color from sensor apds.readColor(r, g, b, a);
                    // Print color in decimal 
                    Console.printf("RED: %d GREEN: %d BLUE: %d AMBIENT: %d\n", r, g, b, a);
                    delay(100);
                    if(myController->b()) {
                        Console.print("button b pressed - exiting to main\n");
                        break;
                    }
                }
            }
            else if(myController->x()) {
                Console.print("button x pressed - entering line mode\n");
                // TODO figure out how to deinitialize these
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
