#include "motors.h"

#define SERVOPIN 13

#define DEADZONE_THRESHOLD 40
#define IN1PIN 26
#define IN2PIN 27
#define IN3PIN 14
#define IN4PIN 12
// #define PWMA 1
// #define PWMB 3

// Servo servo;


bool needExit = false; // for cancel in challenges

// assumes only one of the two joysticks are being moved at a time
// left stick turns
// right stick moves forward/backward

void initMotors() {    
    // servo.attach(SERVOPIN);
    pinMode(IN1PIN, OUTPUT);
    pinMode(IN2PIN, OUTPUT);
    pinMode(IN3PIN, OUTPUT);
    pinMode(IN4PIN, OUTPUT);
    // pinMode(PWMA, OUTPUT);
    // pinMode(PWMB, OUTPUT);
    Console.println("init'ing motors");
}


void goStraight() {
    Console.println("straight");
    // analogWrite(PWMA, val);
    // analogWrite(PWMB, val);
    digitalWrite(IN1PIN, LOW);
    digitalWrite(IN2PIN, HIGH);
    digitalWrite(IN3PIN, HIGH);
    digitalWrite(IN4PIN, LOW);
}

void goBack() {
    Console.println("back");
    // analogWrite(PWMA, val);
    // analogWrite(PWMB, val);
    digitalWrite(IN1PIN, HIGH);
    digitalWrite(IN2PIN, LOW);
    digitalWrite(IN3PIN, LOW);
    digitalWrite(IN4PIN, HIGH);
}

void turnLeft() {
    Console.println("left");
    digitalWrite(IN1PIN, HIGH);
    digitalWrite(IN2PIN, LOW);
    digitalWrite(IN3PIN, HIGH);
    digitalWrite(IN4PIN, LOW);
}

void turnRight() {
    Console.println("right");
    digitalWrite(IN1PIN, LOW);
    digitalWrite(IN2PIN, HIGH);
    digitalWrite(IN3PIN, LOW);
    digitalWrite(IN4PIN, HIGH);
}

void stop() {
    Console.println("stop");
    digitalWrite(IN1PIN, LOW);
    digitalWrite(IN2PIN, LOW);
    digitalWrite(IN3PIN, LOW);
    digitalWrite(IN4PIN, LOW);
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
        // goStraight(abs(((double)myController->axisRY()) / 512) * 256);
        goStraight();
    }
    else if(myController->axisRY() > DEADZONE_THRESHOLD) {
        // goBack(abs(((double)myController->axisRY()) / 512) * 256);
        goBack();
    }
    else {
        stop();
    }
}

