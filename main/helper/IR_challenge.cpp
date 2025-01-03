#include "challenges.h"

ESP32SharpIR IRSensorName(ESP32SharpIR::GP2Y0A21YK0F, 12);

void IRChallenge(ControllerPtr myController) {
    IRSensorName.setFilterRate(1.0f);
    float distance;
    while(1) {
        BP32.update();
        distance = IRSensorName.getDistanceFloat();
        Console.println(distance); 
        if(myController->b()) {
            Console.println("button b pressed - exiting to main");
            break;
        }
    }   
}