#include "sdkconfig.h"
#include <Arduino.h>
#include <ESP32Servo.h>
#include <Bluepad32.h>
#include <uni.h>
#include "controller_callbacks.h"
#include "MotorMovements.h"

#define IN1  16  // Control pin 1
#define IN2  17  // Control pin 2
#define IN3  22 // Control pin 3
#define IN4  23 // Control pin 4

extern ControllerPtr myControllers[BP32_MAX_GAMEPADS]; // BP32 library allows for up to 4 concurrent controller connections, but we only need 1

void GoForward(int duty){
    //Left Motor Forward
    analogWrite(IN1,duty);
    digitalWrite(IN2, LOW);
    //Right Motor Forward
    analogWrite(IN3,duty);
    digitalWrite(IN4,LOW);
}

void GoBackward(int duty){
    //Spin Motor 1
    digitalWrite(IN1,LOW);
    analogWrite(IN2, duty);

    //Spin motor 2 
    digitalWrite(IN3, LOW);
    analogWrite(IN4, duty);
    
}

void GoLeft(int duty){
    
    digitalWrite(IN1, LOW);
    analogWrite(IN2, duty);
    analogWrite(IN3,duty);
    digitalWrite(IN4,LOW);


}

void GoRight(int duty){
    
    analogWrite(IN1,duty);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3,LOW);
    analogWrite(IN4,duty);


}

void Stop(){
    
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
    

}




