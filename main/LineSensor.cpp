#include "sdkconfig.h"
#include <Arduino.h>

#include <QTRSensors.h>
#include <ArduinoConsole.h>

class LineSensor{
    QTRSensors qtr;
    uint16_t sensors[4];
    public:
    LineSensor(int sensorPin1, int sensorPin2, int sensorPin3, int sensorPin4){
        Serial.begin(115200);
        qtr.setTypeAnalog(); // or setTypeAnalog()
        qtr.setSensorPins((const uint8_t[]) {sensorPin1, sensorPin2, sensorPin3, sensorPin4}, 2); // pin numbers go in the curly brackets {}, and number of sensors in use goes after

        // calibration sequence
        for (uint8_t i = 0; i < 250; i++) { 
            Console.printf("calibrating %d/250\n", i); // 250 is the number of calibrations recommended by manufacturer
            qtr.calibrate(); 
            delay(20);
        }
    }

    uint16_t* getValues(){
        qtr.readLineBlack(sensors); // Get calibrated sensor values returned into sensors[]
        Console.printf("S1: %d S2: %d S3: %d S4: %d\n", sensors[0], sensors[1], sensors[2], sensors[3]);
        delay(250);
        return sensors;
    }
};