#pragma once

#ifndef CHALLENGES_H
#define CHALLENGES_H

#include <Arduino.h>
#include <Bluepad32.h>

#include <Arduino_APDS9960.h>
#include <Wire.h>
#include <QTRSensors.h>
#include <ESP32Servo.h>
#include <QTRSensors.h>
#include <ESP32SharpIR.h>
#include "motors.h"

extern bool needExit;
void colorChallenge(ControllerPtr myController);
void lineChallenge(ControllerPtr myController, bool lineIsCalibrated);
void IRChallenge(ControllerPtr myController);

#endif // CHALLENGES_H