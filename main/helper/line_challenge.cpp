#include "challenges.h"

QTRSensors qtr;
uint16_t sensors[2];

void lineChallenge(ControllerPtr myController) {
    qtr.setTypeAnalog(); // or setTypeAnalog()

    const uint8_t pins[] = {33, 32};
    const uint8_t numPins = 2;
    qtr.setSensorPins(pins, numPins);
    for (uint8_t i = 0; i < 250; i++) { 
        Console.println("calibrating");
        qtr.calibrate(); 
        delay(20);
    }
    while(1) {
        BP32.update();
        qtr.readLineBlack(sensors); // Get calibrated sensor values returned in the sensors array
        Console.printf("S1: %d S2: %d\n", sensors[0], sensors[1]);
        delay(50);
        if(myController->b()) {
            Console.println("button b pressed - exiting to main");
            break;
        }
    }   
}
