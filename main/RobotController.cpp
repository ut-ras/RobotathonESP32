#include "sdkconfig.h"
#include <Arduino.h>
#include <Bluepad32.h>
#include <uni.h>
#include "controller_callbacks.h"

#include "Drivetrain.h"
#include "LineSensor.h"
#include "ColorSensor.h"
#include "Routine.h"
#include "DistanceSensor.h"
#include "LineFollow.cpp"
#include "ColorFind.cpp"
#include "MazeSolver.cpp"

#define IN1  16  // Control pin 1
#define IN2  17  // Control pin 2
#define IN3  19  // Control pin 3
#define IN4  18  // Control pin 4

#define OUT1 14
#define OUT2 12
#define OUT3 27
#define OUT4 26
#define OUT5 25
#define OUT6 33
#define OUT7 32
#define OUT8 35

#define ColorSCL 22 // SCL
#define ColorSDA 21 // SDA

#define IRLeft 34
#define IRMiddle 39
#define IRRight 36

#define LED 2

Drivetrain* drivetrain;
LineSensor* lineSensor;
ColorSensor* colorSensor;
DistanceSensor* distanceSensor;

Routine* routine;

extern ControllerPtr myControllers[BP32_MAX_GAMEPADS]; // BP32 library allows for up to 4 concurrent controller connections, but we only need 1

void handleController(ControllerPtr myController) {
    float forward = static_cast<float>(myController->axisY())/512.0;  // L2 analog value for forward
    float turn = static_cast<float>(myController->axisX())/512.0;
    //turn left is negative X axis, left motor goes back while right motor goes forward
    int speedLeft = -(forward - turn) * 255;
    int speedRight = -(forward + turn) * 255;
    //Simple direction control - no braking, no state tracking
    if(routine == nullptr){
        if (myController->r2()) {  // ZR button for forward
        drivetrain->setSpeed(speedLeft, speedRight);
        }
        else if (myController->l2()){
        drivetrain->setSpeed(-speedLeft, -speedRight);
        }
        else{
        drivetrain->setSpeed(0, 0);
        }
    }

    if (myController->x()) {
        routine = new ColorFind(colorSensor, drivetrain);
        digitalWrite(LED, HIGH); // Turn on LED
        Serial.printf("Color Find Routine Started\n");
    } 
    else if (myController->y()) {
        routine = new LineFollow(lineSensor, drivetrain);
        digitalWrite(LED, LOW); // Turn off LED
        Serial.printf("Line Follow Routine Started\n");
    }
    else if (myController->a()) {
        routine = new MazeSolver(distanceSensor, drivetrain);
        digitalWrite(LED, LOW); // Turn off LED
        Serial.printf("Maze Solver Routine Started\n");
    }
    else if (myController->b()) {
        routine = nullptr; // Stop any routine
        digitalWrite(LED, LOW); // Turn off LED
        Serial.printf("No Routine Started\n");
    }
    
}

void setup() {
    Serial.begin(115200);
    uni_bt_allowlist_set_enabled(true); // Enable allowlist first
    BP32.setup(&onConnectedController, &onDisconnectedController);
    esp_log_level_set("gpio", ESP_LOG_ERROR); // Suppress info log spam from gpio_isr_service
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    pinMode(LED, OUTPUT);

    pinMode(OUT1, INPUT);
    pinMode(OUT2, INPUT);
    pinMode(OUT3, INPUT);
    pinMode(OUT4, INPUT);
    pinMode(OUT5, INPUT);
    pinMode(OUT6, INPUT);
    pinMode(OUT7, INPUT);
    pinMode(OUT8, INPUT);

    pinMode(ColorSCL, INPUT);
    pinMode(ColorSDA, INPUT);

    pinMode(IRLeft, INPUT);
    pinMode(IRMiddle, INPUT);
    pinMode(IRRight, INPUT);

    drivetrain = new Drivetrain(IN1, IN2, IN3, IN4);
    lineSensor = new LineSensor(OUT1, OUT2, OUT3, OUT4, OUT5, OUT6, OUT7, OUT8);
    colorSensor = new ColorSensor(ColorSDA, ColorSCL);
    distanceSensor = new DistanceSensor(IRLeft, IRMiddle, IRRight);
}

void loop() {
    static unsigned long lastDebugTime = 0;
    
    BP32.update(); // Update the gamepad state
    
    // Print debug info every 5 seconds if no controller is connected
    unsigned long currentTime = millis();
    if (currentTime - lastDebugTime >= 5000) {
        bool anyConnected = false;
        for (auto myController : myControllers) {
            if (myController && myController->isConnected()) {
                anyConnected = true;
                Serial.printf("Controller connected - Battery: %d%%\n", myController->battery());
            }
        }
        if (!anyConnected) {
            Serial.println("Waiting for controller connection...");
        }
        lastDebugTime = currentTime;
    }
    
    //Handle connected controllers
    for (auto myController : myControllers) {
       if (myController && myController->isConnected() && myController->hasData()) {
           handleController(myController);
       }
    }

    if(routine != nullptr){
        //Console.printf("Running Routine\n");
        routine->update();
    }
    //Console.printf("Running Loop\n");
    vTaskDelay(1); // Small delay to prevent watchdog issues
}
