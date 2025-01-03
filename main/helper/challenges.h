#include <Arduino.h>
#include <Bluepad32.h>

#include <Arduino_APDS9960.h>
#include <Wire.h>
#include <QTRSensors.h>
#include <ESP32Servo.h>
#include <QTRSensors.h>
#include <ESP32SharpIR.h>

#include "motors.h"

void colorChallenge(ControllerPtr myController);
void lineChallenge(ControllerPtr myController);
void IRChallenge(ControllerPtr myController);

void testNVS();