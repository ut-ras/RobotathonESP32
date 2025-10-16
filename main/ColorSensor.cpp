#include "sdkconfig.h"
#include <Arduino.h>

#include <Wire.h>
#include <Arduino_APDS9960.h>
#include <bits/stdc++.h>

class ColorSensor{
    static const int sensorPin1 = 0;
    static const int sensonPin2 = 0;
    static const int sensorInteruptPin = 2;
    static const int sensorFrequency = 0;

    TwoWire sensorProtocol = TwoWire(0);
    APDS9960 colorSensor = APDS9960(sensorProtocol, sensorInteruptPin);

    ColorSensor(){
        //sets up I2C protocol
        sensorProtocol.begin(sensorPin1, sensonPin2, sensorFrequency);

        //sets up color sensor
        colorSensor.setInterruptPin(sensorInteruptPin);
        colorSensor.begin();
        Serial.begin(115200);
    }

    int* getColors(){
        int r, g, b, a;

        while (!colorSensor.colorAvailable()) { // Wait until color is read from the sensor 
            delay(5); 
        }

        colorSensor.readColor(r, g, b, a);
        delay(50);

        int num[] = {r, g, b, a};
        return num;
    }
};