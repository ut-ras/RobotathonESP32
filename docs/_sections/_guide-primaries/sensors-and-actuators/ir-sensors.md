---
layout: default
title: IR Sensor
nav_include: true
parent: Sensors and Actuators
nav_order: 1
---

# IR Sensor

<img src="{{ '/_assets/images/ir_sensor.png' | prepend: site.baseurl }}" alt="ir_sensor.png" width=200 height=300>

A necessary component for any challenge that utilizes walls, analog IR sensors are a staple of Robotathon. This particular sensor is the GP2Y0A21, and detects distances from 10 to 80 cm.

## How it Works
IR distance sensors emit bursts of infrared light towards a surface. The light bounces off objects it hits, and then enters a proximity sensor. The output is then transformed into a voltage (see graph below) that can be read by the ESP32. See [this link for more information.](https://www.pololu.com/product/136)

<img src="{{ '/_assets/images/ir-sensor-functionality.png' | prepend: site.baseurl }}" alt="ir-sensor-functionality.png">
<img src="{{ '/_assets/images/ir-sensor-graph.png' | prepend: site.baseurl }}" alt="IR-sensor-graph.png">

## Interfacing
There are 3 pins (red, black, white) to the device as seen in the picture, associated to Power, Ground, and Output Signal, respectively. For testing the distance sensor, let’s use the analog pin, pin 27, as the signal pin. Hook up the circuit as follows:

{: .highlight}
Note that some of our IR sensors may have preattached cables with incorrect color coding. Be sure to follow the colors shown in the first picture!
{: .callout-toby}

|  IR Sensor Pin   | ESP32 Pin          |
|:-------------|:------------------|
| VIN  (red)         | 3.3V                      |
| GND  (black)        | GND      |
| Signal (white)       |  Any ADC Capable Pin    |

{: .highlight}
If you're not sure which ESP32 pins are ADC (Analog to Digital Converter) capable, then check out the diagram in [this page!](https://ut-ras.github.io/RobotathonESP32/getting-started/microcontroller-interface)
{: .callout-toby}

## Programming 
The following program will allow you to read values from the IR sensor in a loop. After you build and flash the program, you should see the values in your terminal output change as you move it towards and away from an object.

```cpp
#include "sdkconfig.h"
#ifndef CONFIG_BLUEPAD32_PLATFORM_ARDUINO
#error "Must only be compiled when using Bluepad32 Arduino platform"
#endif  // !CONFIG_BLUEPAD32_PLATFORM_ARDUINO
#include <Arduino.h>

#include <ESP32SharpIR.h>

void setup() {
    Serial.begin(115200);
    ESP32SharpIR IRSensorName(ESP32SharpIR::GP2Y0A21YKOF, 27);
    IRSensorName.setFilterRate(0.1f);
}
    
void loop() {
    Serial.println(IRSensorName.getDistanceFloat()); 
    delay(500);
}
```


## Extensions
You received values from the sensor, but do they mean anything? The next step for the IR sensor is translating and thresholding it. Take a look at the above graph. There is a strong linear relationship between your signal value and the inverse of the distance away from the object. It’s your job now to code a function that returns an accurate distance given a voltage input value. After that, your team needs to threshold the data. When do the values become inconsistent (too close or too far)? What do you do with your robot when that happens?


