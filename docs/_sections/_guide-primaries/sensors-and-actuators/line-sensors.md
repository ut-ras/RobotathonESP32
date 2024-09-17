---
layout: default
title: Line Sensor
nav_include: true
parent: Sensors and Actuators
nav_order: 1
---

# Line Sensor (UNEDTIED)
A necessary component for any challenge that requires your robot to follow a line. This one is the QTR-8A Reflectance Sensor Array and uses IR transmitters and receivers on it to detect lines.

## How it Works
The line sensor is made up of an array of 8 IR LED/phototransistor pairs, each take an analog reflectance reading by timing how long it takes the output voltage to decay due to the phototransistor. By pointing the line sensor IR LEDs/phototransistors at the line, the robot is able to tell where the dark line of tape is by reading the output voltage of each phototransistor

<img src="{{ '/_assets/images/line_sensor_diodes.png' | prepend: site.baseurl }}" alt="line_sensor_diodes.png">

{: .highlight}
Note: you do NOT have to use all of the LED/phototransistor pairs — You can leave the ones you do not want to use disconnected from the ESP32.
{: .callout-toby}

## Programming
The following program will allow you to continuously read a general position value of the sensor across a line. After you build and flash the program, you should see the values in the UART change as you shift the line across the 
different sensors.

```cpp

#include "sdkconfig.h"
#ifndef CONFIG_BLUEPAD32_PLATFORM_ARDUINO
#error "Must only be compiled when using Bluepad32 Arduino platform"
#endif  // !CONFIG_BLUEPAD32_PLATFORM_ARDUINO
#include <Arduino.h>

#include <QTRSensors.h>

QTRSensors qtr;
uint16_t sensors[3];

void setup() {
    // set up Serial Communication and sensor pins
    Serial.begin(115200);
    qtr.setTypeAnalog(); // or setTypeAnalog()
    qtr.setSensorPins((const uint8_t[]) {36, 39, 34}, 3); // pin numbers go in the curly brackets {}, and number of pins goes after

    // calibration sequence
    for (uint8_t i = 0; i < 250; i++) { 
        Serial.println("calibrating");
        qtr.calibrate(); 
        delay(20);
    }
}

void loop() {
    // Get calibrated sensor values returned in the sensors array, along with the 
    // line position, which will range from 0 to 2000, with 1000 corresponding to
    // a position under the middle sensor.
    qtr.readLineBlack(sensors);
    Serial.print(sensors[0]);
    Serial.print(" ");
    Serial.print(sensors[1]);
    Serial.print(" ");
    Serial.println(sensors[2]);
    delay(250);
}

```

TIP: always run the calibrate function (i.e. hold a line of the color you’re sensing under all the sensors during set up) to ensure consistent and accurate results.

## Extensions
* You received values from the sensor, but what do they mean? 
* How does the position value change as you place your line beneath different sensors, and how can you control that? 
* Is there an easier way to quantify the “change” when the car is veering off the line?
* What do you do with your robot when that happens? I.e. adjusting movement
* Consistency in data collection is key for calibration
 * Can you automate the calibration process?


<img src="{{ '/_assets/images/line_sensor_wiring.png' | prepend: site.baseurl }}" alt="line_sensor_wiring.png">
