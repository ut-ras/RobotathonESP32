#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <Arduino.h>
#include <QTRSensors.h>
#include <ArduinoConsole.h>

class LineSensor {
    QTRSensors qtr;
    uint16_t sensors[4];
public:
    LineSensor(uint8_t sensorPin1, uint8_t sensorPin2, uint8_t sensorPin3, uint8_t sensorPin4);
    uint16_t* getValues();
};

#endif