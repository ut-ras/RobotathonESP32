#include "motors.h"

#define DEADZONE_THRESHOLD 10
#define A1PIN 19
#define A2PIN 18
#define B1PIN 5
#define B2PIN 17
#define PWMA 1
#define PWMB 3

bool needExit = false; // for cancel in challenges

// assumes only one of the two joysticks are being moved at a time
// left stick turns
// right stick moves forward/backward

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
        goStraight();
    }
    else if(myController->axisRY() > DEADZONE_THRESHOLD) {
        goBack();
    }
    else {
        stop();
    }
}

void goStraight() {
    Console.println("straight");
}

void goBack() {
    Console.println("back");
}

void turnLeft() {
    Console.println("left");
}

void turnRight() {
    Console.println("right");
}

void stop() {
    Console.println("stop");
}

