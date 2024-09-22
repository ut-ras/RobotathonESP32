---
layout: default
title: IR Sensor
nav_include: true
parent: Sensors and Actuators
nav_order: 2
---

# IR Sensor

<img src="{{ '/_assets/images/ir_sensor.png' | prepend: site.baseurl }}" alt="ir_sensor.png" width=200 height=300>

A necessary component for any challenge that utilizes walls, analog IR sensors are a staple of Robotathon. This particular sensor is the GP2Y0A21YK0F model.

## How it Works
IR distance sensors emit bursts of infrared light towards a surface. The light bounces off objects it hits, and then enters a proximity sensor. The output is then transformed into a voltage (see graph below) that can be read by the ESP32. See [this link for more information.](https://www.pololu.com/product/136)

<img src="{{ '/_assets/images/ir-sensor-functionality.png' | prepend: site.baseurl }}" alt="ir-sensor-functionality.png">
<img src="{{ '/_assets/images/ir-sensor-graph.png' | prepend: site.baseurl }}" alt="IR-sensor-graph.png">

Notice that the sensor will output garbage if the sensor is too close to an object.

## Interfacing
There are 3 pins (red, black, white) to the device as seen in the picture, associated to Power, Ground, and Output Signal, respectively. For testing the distance sensor, let’s use pin 12, as the signal pin. Hook up the circuit as follows:

<!-- <img src="{{ '/_assets/images/ir_sensor_wiring.png' | prepend: site.baseurl }}" alt="ir_sensor_wiring.png"> -->
<!-- decided not to include the above picture because it might be confusing with the adapter being the wrong colors lol -->


{: .highlight}
Note that some of our IR sensors may have preattached cables with incorrect color coding (Red and Black got switched). Be sure to follow the order shown in the first picture!
{: .callout-toby}

|  IR Sensor Pin   | ESP32 Pin          |
|:-------------|:------------------|
| VIN  (Red)| 5V                      |
| GND      (Black)    | GND      |
| Signal    (White)   |  Any ADC Capable Pin    |

If you're not sure about the ESP32 pinout then check out the diagram in [this page!](https://ut-ras.github.io/RobotathonESP32/getting-started/microcontroller-interface)

## Programming 
The following program will allow you to read values from the IR sensor in a loop. After you build and flash the program, you should see the values in your terminal change as you move it towards and away from an object.

```cpp
#include "sdkconfig.h"
#include <Arduino.h>

#include <ESP32SharpIR.h>

ESP32SharpIR IRSensorName(ESP32SharpIR::GP2Y0A21YK0F, 12);

void setup() {
    Serial.begin(115200);
    IRSensorName.setFilterRate(1.0f);
}
    
void loop() {
    Serial.println(IRSensorName.getDistanceFloat()); 
    delay(100);
}
```

## Extensions
You received values from the sensor, but do they mean anything? The next step for the IR sensor is translating and thresholding it. Take a look at the above graph. There is a strong linear relationship between your signal value and the distance away from the object. It’s your job now to code a function that returns an accurate distance given a voltage input value. After that, your team needs to threshold the data. When do the values become inconsistent (too close or too far)? What do you do with your robot when that happens?


