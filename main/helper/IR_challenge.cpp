#include "challenges.h"

#define IR1_PIN 32 //should be right
#define IR2_PIN 33 //should be left
//#define IR3_PIN 25 //mentor has no middle

ESP32SharpIR leftIR(ESP32SharpIR::GP2Y0A21YK0F, IR2_PIN);
//ESP32SharpIR middleIR(ESP32SharpIR::GP2Y0A21YK0F, IR_PIN);
ESP32SharpIR rightIR(ESP32SharpIR::GP2Y0A21YK0F, IR1_PIN);

void IRChallenge(ControllerPtr myController) {
    leftIR.setFilterRate(5.0f);
    //middleIR.setFilterRate(5.0f);
    rightIR.setFilterRate(5.0f);
    int leftDistance;
    int middleDistance;
    int rightDistance;
    int filterMode = 0;
    while(1) {
        BP32.update();
        if(myController->y()) {
            filterMode++;
            if(filterMode > 3) filterMode = 0;
            if(filterMode == 0) {
                Console.printf("Switching to 5.0f\n");
                delay(1000);
                leftIR.setFilterRate(5.0f);
                //middleIR.setFilterRate(5.0f);
                rightIR.setFilterRate(5.0f);
            }
            if(filterMode == 1) {
                Console.printf("Switching to 1.0f\n");
                delay(1000);
                leftIR.setFilterRate(1.0f);
                //middleIR.setFilterRate(1.0f);
                rightIR.setFilterRate(1.0f);
            }
            if(filterMode == 2) {
                Console.printf("Switching to 0.5f\n");
                delay(1000);
                leftIR.setFilterRate(0.5f);
                //middleIR.setFilterRate(0.5f);
                rightIR.setFilterRate(0.5f);
            }
            if(filterMode == 3) {
                Console.printf("Switching to 0.1f\n");
                delay(1000);
                leftIR.setFilterRate(0.1f);
                //middleIR.setFilterRate(0.1f);
                rightIR.setFilterRate(0.1f);
            }
        }
        leftDistance = leftIR.getRawDistance();
        //middleDistance = middleIR.getRawDistance();
        rightDistance = rightIR.getRawDistance();
        Console.printf("left: %d right: %d\n", leftDistance, rightDistance); 
        delay(100);
        if(myController->b()) {
            Console.println("button b pressed - exiting to main");
            break;
        }
        if ((leftDistance * 2)  <= rightDistance) {
            turnRight();
            turnRight();
            delay(100);
        } else if ((rightDistance * 2) <= leftDistance) {
            turnLeft();
            turnLeft();
            delay(100);
        } else {
            goStraight();
            delay(100);
        }
    }   
}