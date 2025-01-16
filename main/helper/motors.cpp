#include "motors.h"

#define SERVOPIN 13

#define DEADZONE_THRESHOLD 10
#define A1PIN 19
#define A2PIN 18
#define B1PIN 5
#define B2PIN 17
#define PWMA 1
#define PWMB 3

Servo servo;


bool needExit = false; // for cancel in challenges

// assumes only one of the two joysticks are being moved at a time
// left stick turns
// right stick moves forward/backward

void initMotors() {    
    servo.attach(SERVOPIN);
    pinMode(A1PIN, OUTPUT);
    pinMode(A2PIN, OUTPUT);
    pinMode(B1PIN, OUTPUT);
    pinMode(B2PIN, OUTPUT);
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
}



void checkCancel(ControllerPtr myController) {
    BP32.update();
    if(myController->b()) {
        Console.print("button b pressed - exiting to main\n");
        stop();
        needExit = true;;
    }
}

void moveMain(ControllerPtr myController) {
    BP32.update();
    if(myController->axisX() > DEADZONE_THRESHOLD) {
        turnRight();
    }
    else if(myController->axisX() < -DEADZONE_THRESHOLD) {
        turnLeft();
    }
    else if(myController->axisRY() < -DEADZONE_THRESHOLD) { // down on the stick is positive
        goStraight(abs(((double)myController->axisRY()) / 512) * 256);
    }
    else if(myController->axisRY() > DEADZONE_THRESHOLD) {
        goBack(abs(((double)myController->axisRY()) / 512) * 256);
    }
    else {
        stop();
    }
}

void goStraight(int val) {
    Console.println("straight");
    analogWrite(PWMA, val);
    analogWrite(PWMB, val);
    digitalWrite(A1PIN, HIGH);
    digitalWrite(A2PIN, LOW);
    digitalWrite(B1PIN, HIGH);
    digitalWrite(B2PIN, LOW);
}

void goBack(int val) {
    Console.println("back");
    analogWrite(PWMA, val);
    analogWrite(PWMB, val);
    digitalWrite(A1PIN, LOW);
    digitalWrite(A2PIN, HIGH);
    digitalWrite(B1PIN, LOW);
    digitalWrite(B2PIN, HIGH);
}

void turnLeft() {
    Console.println("left");
    digitalWrite(A1PIN, HIGH);
    digitalWrite(A2PIN, LOW);
    digitalWrite(B1PIN, LOW);
    digitalWrite(B2PIN, LOW);
}

void turnRight() {
    Console.println("right");
    digitalWrite(A1PIN, LOW);
    digitalWrite(A2PIN, LOW);
    digitalWrite(B1PIN, HIGH);
    digitalWrite(B2PIN, LOW);
}

void stop() {
    Console.println("stop");
    digitalWrite(A1PIN, LOW);
    digitalWrite(A2PIN, LOW);
    digitalWrite(B1PIN, LOW);
    digitalWrite(B2PIN, LOW);
}

