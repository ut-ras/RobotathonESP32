#include "LineSensor.h"

LineSensor::LineSensor(uint8_t sensorPin1, uint8_t sensorPin2, uint8_t sensorPin3, uint8_t sensorPin4) {
    qtr.setTypeAnalog();

    uint8_t pins[4] = {sensorPin1, sensorPin2, sensorPin3, sensorPin4};
    qtr.setSensorPins(pins, 4);

    // calibration sequence
    for (uint8_t i = 0; i < 250; i++) {
        Console.printf("calibrating %d/250\n", i);
        qtr.calibrate();
        delay(20);
    }
}

std::array<uint16_t,4> LineSensor::getValues() {
    uint16_t sensors[4] = {0,0,0,0};
    qtr.readLineBlack(sensors);
    Console.printf("Line Sensor: S1: %d S2: %d S3: %d S4: %d\n", sensors[0], sensors[1], sensors[2], sensors[3]);
    delay(250);
    std::array<uint16_t, 4> vals = {sensors[0], sensors[1], sensors[2], sensors[3]};
    return vals;
}