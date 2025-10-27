#include "sdkconfig.h"
#include <Arduino.h>

#include <Wire.h>
#include <Arduino_APDS9960.h>
#include <bits/stdc++.h>

class Drivetrain{
    int motorPin1;
    int motorPin2;
    int motorPin3;
    int motorPin4;

    public:
    Drivetrain(int pin1, int pin2, int pin3, int pin4){
        this->motorPin1 = pin1;
        this->motorPin2 = pin2;
        this->motorPin3 = pin3;
        this->motorPin4 = pin4;
    }

    void setSpeed(int left, int right){
        if(left < 0){
            left *= -1;
            digitalWrite(motorPin1, LOW);   // Backwards
            analogWrite(motorPin2, left);
        }
        else{
            digitalWrite(motorPin2, LOW);
            analogWrite(motorPin1, left);   // Forwards
        }
        if(right < 0){
            right *= -1;
            digitalWrite(motorPin3, LOW);   // Backwards
            analogWrite(motorPin4, right);
        }
        else{
            digitalWrite(motorPin4, LOW);
            analogWrite(motorPin3, right);  // Forwards
        }
    }
};