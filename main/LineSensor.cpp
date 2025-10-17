#include "sdkconfig.h"
#include <Arduino.h>

#include <QTRSensors.h>

QTRSensors qtr;
uint16_t sensors[2];

void setup() {
    // set up Serial Communication and sensor pins
    Serial.begin(115200);
    qtr.setTypeAnalog(); // or setTypeAnalog()
    qtr.setSensorPins((const uint8_t[]) {32, 33}, 2); // pin numbers go in the curly brackets {}, and number of sensors in use goes after

    // calibration sequence
    for (uint8_t i = 0; i < 250; i++) { 
        Console.printf("calibrating %d/250\n", i); // 250 is the number of calibrations recommended by manufacturer
        qtr.calibrate(); 
        delay(20);
    }
}

void loop() {
    qtr.readLineBlack(sensors); // Get calibrated sensor values returned into sensors[]
    Console.printf("S1: %d S2: %d\n", sensors[0], sensors[1]);
    delay(250);
}