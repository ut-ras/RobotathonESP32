#include "sdkconfig.h"
#include <Arduino.h>
#include <ESP32Servo.h>
#include <Bluepad32.h>
#include <uni.h>
#include "controller_callbacks.h"

#define IN1  16  // Control pin 1
#define IN2  17  // Control pin 2
#define IN3  22 // Control pin 3
#define IN4  23 // Control pin 4

extern ControllerPtr myControllers[BP32_MAX_GAMEPADS]; // BP32 library allows for up to 4 concurrent controller connections, but we only need 1

void GoForward(int duty);

void GoBackward(int duty);

void GoLeft(int duty);

void GoRight(int duty);

void Stop();
