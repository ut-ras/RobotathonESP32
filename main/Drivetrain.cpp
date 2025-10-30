#include "Drivetrain.h"

Drivetrain::Drivetrain(int pin1, int pin2, int pin3, int pin4) {
    motorPin1 = pin1;
    motorPin2 = pin2;
    motorPin3 = pin3;
    motorPin4 = pin4;
}

void Drivetrain::setSpeed(int left, int right) {
    if (left < 0) {
        left *= -1;
        digitalWrite(motorPin1, LOW);
        analogWrite(motorPin2, left);
    } 
    else if(left > 0) {
        digitalWrite(motorPin2, LOW);
        analogWrite(motorPin1, left);
    }
    else{
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        analogWrite(motorPin1, 0);
        analogWrite(motorPin2, 0);
    }

    if (right < 0) {
        right *= -1;
        digitalWrite(motorPin3, LOW);
        analogWrite(motorPin4, right);
    } 
    else if(right > 0){
        digitalWrite(motorPin4, LOW);
        analogWrite(motorPin3, right);
    }
    else{
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        analogWrite(motorPin3, 0);
        analogWrite(motorPin4, 0);
    }
    delay(50);
}