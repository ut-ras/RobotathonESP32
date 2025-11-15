#ifndef COLORSENSOR_H
#define COLORSENSOR_H

#include "sdkconfig.h"
#include <Arduino.h>

#include <Wire.h>
#include <Arduino_APDS9960.h>
#include <bits/stdc++.h>

class ColorSensor{
    int SDA;
    int SCL;
    int APSD9960INT = 0;
    int sensorFrequency = 100000;
    TwoWire sensorProtocol = TwoWire(0);
    APDS9960 *colorSensor; // pointer to APDS9960 instance

    public:
    ColorSensor(int pin1, int pin2);
    std::array<int,4> getColors();
};

#endif