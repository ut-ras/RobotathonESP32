#include "motors.h"
#define DEADZONE_THRESHOLD 10
// assumes only one of the two joysticks are being moved at a time
// left stick turns
// right stick moves forward/backward
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

