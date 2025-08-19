---
layout: default
title: Color Sensor
nav_include: true
parent: Hardware
nav_order: 2
---

# Color Sensor
The APDS-9960 Color Sensor will allow you to complete the Color Challenge by enabling your robot to see colors!

## Workshop Slides
<iframe src="https://docs.google.com/presentation/d/1h5p9pCGCKSqfrkFSnQQ6bxtwjZGJe90FrfASYaGZwRY/embed?start=false" 
        frameborder="0" 
        width="960" 
        height="569" 
        allowfullscreen="true" 
        mozallowfullscreen="true" 
        webkitallowfullscreen="true">
</iframe>




## How it Works
The RGB (Red Green Blue) sensor has an infrared LED light that detects color by emitting light and detecting with four photodiodes the reflected light. The photodiodoes are each filtered to sense the Red, Green, Blue, and Clear color components. The RGB provides the R G and B strength in integer values of 0-255 (8 bit representation). We will grab that data using a communication protocol called I2C (inter-integrated circuit), which is used in many electrical devices. Implementing I2C on our own is out of the scope of this competition, but you can find more information about it [here.](https://learn.sparkfun.com/tutorials/i2c/all)

You will definitely want to keep in mind that the sensor is affected by ambient light levels and proximity, so make sure your color sensor is placed appropriately and has sufficient external lighting to accurately read colors and complete the challenge.

If you want more details on how the color sensor works, check out [this link!](https://www.utmel.com/components/everything-you-know-about-tcs34725-color-sensors-faq?id=1986)

Here is a wiring diagram:

<img src="{{ '/_assets/images/color_sensor_wiring.png' | prepend: site.baseurl }}" alt="color_sensor_wiring.png">

|  Color Sensor Pin   | ESP32 Pin          |
|:-------------|:------------------|
| VIN          | 3.3V                      |
| GND        | GND      |
| SDA       |  GPIO21   |
| SCL     |  GPIO22    |

If you're not sure about the ESP32 pinout, then check out [this page!](https://ut-ras.github.io/RobotathonESP32/getting-started/microcontroller-interface)

{: .highlight}
Make sure to connect the color sensor's power pin to 3.3V! A 5V connection will fry the sensor.
{: .callout-red}

The SDA and SCL on the color sensor MUST be connected to the specified GPIO pins on the ESP32. This is because they are the dedicated pins for I2C commmunication.

## Programming
For this tutorial, we’re only going to be reading the color sensor values. Make sure that your pins are correctly connected or otherwise you won’t receive any data!

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
    while (!apds.colorAvailable()) { delay(5); } // Wait until color is read from the sensor 
    apds.readColor(r, g, b, a);
    Console.printf("RED: %d GREEN: %d BLUE: %d AMBIENT: %d\n", r, g, b, a);
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

