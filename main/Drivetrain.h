#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <Arduino.h>

class Drivetrain {
    int motorPin1;
    int motorPin2;
    int motorPin3;
    int motorPin4;

public:
    Drivetrain(int pin1, int pin2, int pin3, int pin4);
    void setSpeed(int left, int right);
};

#endif