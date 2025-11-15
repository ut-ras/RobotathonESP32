#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include "sdkconfig.h"
#include <Arduino.h>

#include <Wire.h>
#include <Arduino_APDS9960.h>
#include <bits/stdc++.h>
#include <ESP32SharpIR.h>

class DistanceSensor{
    ESP32SharpIR *IRSensorLeft;
    ESP32SharpIR *IRSensorMiddle;
    ESP32SharpIR *IRSensorRight;

    public:
    DistanceSensor(int pinLeft, int pinMiddle, int pinRight);
    std::array<int,3> getValues();
};

#endif