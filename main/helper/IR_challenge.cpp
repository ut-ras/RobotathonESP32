#include "challenges.h"

#define IR1_PIN 39
#define IR2_PIN 34
#define IR3_PIN 35

ESP32SharpIR IR1(ESP32SharpIR::GP2Y0A21YK0F, IR1_PIN);
ESP32SharpIR IR2(ESP32SharpIR::GP2Y0A21YK0F, IR2_PIN);
ESP32SharpIR IR3(ESP32SharpIR::GP2Y0A21YK0F, IR3_PIN);

void IRChallenge(ControllerPtr myController) {
    IR1.setFilterRate(1.0f);
    IR2.setFilterRate(1.0f);
    IR3.setFilterRate(1.0f);
    float distance;
    while(1) {
        BP32.update();
        distance = IR1.getDistanceFloat();
        Console.println(distance); 
        delay(100);
        if(myController->b()) {
            Console.println("button b pressed - exiting to main");
            break;
        }
    }   
}