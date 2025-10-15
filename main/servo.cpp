include "sdkconfig.h"
include <Arduino.h>

include <ESP32Servo.h>

Servo myServo;

void setup() {
  myServo.attach(12);
    myServo.write(0); // Rotate to 0 degrees
  delay(1000); // Delay 1000 ms
  myServo.write(180); // Rotate to 180 degrees
  delay(1000);

  vTaskDelay(1); // Yield CPU to not starve other ESP32 processes and cause WDT reset

}

void loop() {
}
