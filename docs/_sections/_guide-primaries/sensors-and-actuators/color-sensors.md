---
layout: default
title: Color Sensor
nav_include: true
parent: Sensors and Actuators
nav_order: 1
---

# Color Sensor
The TCS34725 from Adafruit will allow you to complete the Color Challenge.

<img src="{{ '/_assets/images/color_sensor.jpg' | prepend: site.baseurl }}" alt="color_sensor.jpg" width=300 height=300>

## How it Works
The RGB sensor uses the RGB color space to represent the color that it sees through photodiodes. It provides the data in integer values of 0-255, represented in 8 binary bits. We will grab that data using a communication protocol called I2C, which is used in many electrical devices. Implementing I2C is out of the scope of this competition, but you can find more information about it [here.](https://learn.sparkfun.com/tutorials/i2c/all)

If you want more details on how the color sensor works, check out [this link!](https://www.utmel.com/components/everything-you-know-about-tcs34725-color-sensors-faq?id=1986)

|  Color Sensor Pin   | ESP32 Pin          |
|:-------------|:------------------|
| VIN          | 3.3V                      |
| GND        | GND      |
| SDA       |  GPIO21   |
| SCL     |  GPIO22    |

## Programming
For this tutorial, we’re only going to be reading the RGB sensor values from the TCS34725. Make sure that your pins are correctly connected or otherwise you won’t receive the data!

```cpp

#include "sdkconfig.h"
#include <Arduino.h>

#include <Wire.h>
#include <Arduino_APDS9960.h>
#include <bits/stdc++.h>

#define APDS9960_INT 2
#define I2C_SDA 21
#define I2C_SCL 22
#define I2C_FREQ 100000

TwoWire I2C_0 = TwoWire(0);
APDS9960 apds = APDS9960(I2C_0, APDS9960_INT);

void setup() {
    //sets up I2C protocol
    I2C_0.begin(I2C_SDA, I2C_SCL, I2C_FREQ);

    //sets up color sensor
    apds.setInterruptPin(APDS9960_INT);
    apds.begin();
    Serial.begin(115200);
}

void loop() {
    int r, g, b, a;
    // Wait until color is read from the sensor 
    while (!apds.colorAvailable()) { delay(5); }
    apds.readColor(r, g, b, a);
    // Read color from sensor apds.readColor(r, g, b, a);
    // Print color in decimal 
    Serial.print("RED: ");
    Serial.print(r);
    Serial.print(" GREEN: ");
    Serial.print(g);
    Serial.print(" BLUE: ");
    Serial.print(b);
    Serial.print(" AMBIENT: ");
    Serial.println(a);
    delay(100);
}
```

# Tips
For the color checkpoint, you need to classify various colors. Try to output the sensor readings on the serial monitior for debugging.

Try to threshold a level of error for your sensor and think about the following questions:
* Do the values change under different lighting? 
 * Inconsistent lighting skewing your results can be remedied with an external white LED
* Different distances? 
* What about various shades of red? Is red one specific RGB value?

