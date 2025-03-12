#include "challenges.h"
#include "esp_system.h"
#include "nvs_flash.h"
// #include "nvs.h"

#define LINE1_PIN 36
#define LINE2_PIN 39
#define LINE3_PIN 34
#define LINE4_PIN 35

#define NUM_LINE_SENSORS 4
#define THRESHOLD 500

QTRSensors qtr;
uint16_t sensors[NUM_LINE_SENSORS];
bool lineIsCalibrated = false; // false will trigger calibration + write to NVS, true will trigger read from NVS

// note that NVS functionality might break if NUM_LINE_SENSORS != 4
void lineChallenge(ControllerPtr myController) {
    qtr.setTypeAnalog();

    const uint8_t pins[] = {LINE1_PIN, LINE2_PIN, LINE3_PIN, LINE4_PIN};
    const uint8_t numSensors = NUM_LINE_SENSORS;
    bool boolSensorData[4];

    qtr.setSensorPins(pins, numSensors);
    if(!lineIsCalibrated) { // only calibrate if necessary. otherwise read calbration data from flash
        pinMode(2, OUTPUT);
        digitalWrite(2, HIGH); // calibration status onboard LED
        for (uint8_t i = 0; i < 250; i++) { 
            Console.printf("calibrating %d/250\n", i);
            qtr.calibrate(); 
            delay(20);
            checkCancel(myController); // no clue if this interferes with calibration significantly lmao
            if(needExit) {
                digitalWrite(2, LOW);
                return;
            }
        }
        qtr.saveCalibration();
        digitalWrite(2, LOW);
    }
    else {
        qtr.restoreSensorCalibration();
    }
    while(1) {
        BP32.update();
        qtr.readLineBlack(sensors); // Get calibrated sensor values returned in the sensors array
        Console.printf("S1: %d S2: %d S3: %d S4: %d\n", sensors[0], sensors[1], sensors[2], sensors[3]);
        delay(50);

        // remap sensors to array of booleans for ease of typing
        // true is line
        // false is no line
        for(int i = 0; i < NUM_LINE_SENSORS; i++) {
            if(sensors[i] < THRESHOLD) {
                boolSensorData[i] = true;
            } else {
                boolSensorData[i] = false;
            }
        }

        // // IIOO
        if(boolSensorData[0] && boolSensorData[1] && !boolSensorData[2] && !boolSensorData[3]) {
            turnLeft();
        }
        // // OOII
        else if(!boolSensorData[0] && !boolSensorData[1] && boolSensorData[2] && boolSensorData[3]) {
            turnRight();
        }
        // // OIIO
        else if(!boolSensorData[0] && boolSensorData[1] && boolSensorData[2] && !boolSensorData[3]) {
            goStraight();
        }
        // // OOOO
        // else if(!boolSensorData[0] && !boolSensorData[1] && !boolSensorData[2] && !boolSensorData[3]) {
        //     turnLeft(); // idk
        // }

        if(myController->b()) {
            Console.println("button b pressed - exiting to main");
            break;
        }
    }   
}
