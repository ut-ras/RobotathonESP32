#include <Arduino.h>
#include <Bluepad32.h>
#include "controller_callbacks.h"

#include <Arduino_APDS9960.h>
#include <Wire.h>

#include <QTRSensors.h>

#include <ESP32Servo.h>
#include <QTRSensors.h>
#include <ESP32SharpIR.h>

void colorChallenge(ControllerPtr myController);