#include <Arduino.h>
#include <Bluepad32.h>
#include <ESP32Servo.h>

void checkCancel(ControllerPtr myController);
void moveMain(ControllerPtr myController);
void goStraight();
void goBack();
void turnLeft();
void turnRight();
void stop();