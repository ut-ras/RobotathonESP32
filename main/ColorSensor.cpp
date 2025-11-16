#include "sdkconfig.h"
#include <Arduino.h>

#include <Wire.h>
#include <Arduino_APDS9960.h>
#include <bits/stdc++.h>
#include <array>

#include "ColorSensor.h"
#include <ArduinoConsole.h>

ColorSensor::ColorSensor(int SDA, int SCL){
    // create the APDS9960 instance on the heap using the local TwoWire
    colorSensor = new APDS9960(sensorProtocol, APSD9960INT);
    //sets up I2C protocol (use constructor parameters for SDA/SCL)
    sensorProtocol.begin(SDA, SCL, sensorFrequency);
    //sets up color sensor
    colorSensor->setInterruptPin(APSD9960INT);

    while (!colorSensor->begin()) {
        delay(150); // Wait before retrying
    }

    delay(150);
}
std::array<int,4> ColorSensor::getColors(){
    int r = 0;
    int g = 0;
    int b = 0;
    int a = 0;


    while (!colorSensor->colorAvailable()) { // Wait until color is read from the sensor 
        delay(5); 
    }

    Serial.println("7");

    colorSensor->readColor(r, g, b, a);
    delay(50);

    Console.printf("Color Sensor: R: %d G: %d B: %d A: %d\n", r, g, b, a);

    return {r, g, b, a};
}