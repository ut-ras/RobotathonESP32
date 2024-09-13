---
layout: default
title: IR Sensor
nav_include: true
parent: Sensors and Actuators
nav_order: 1
---

# IR Sensor (UNEDITED)

<img src="{{ '/_assets/images/ir_sensor.png' | prepend: site.baseurl }}" alt="ir_sensor.png">

A necessary component for any challenge that utilizes walls, analog IR sensors are a staple of Robotathon. This particular sensor is the GP2Y0A21, and detects distances from 10 to 80 cm.

## How it Works
IR distance sensors emit long wavelength (700 nm - 1 mm) light towards a surface. The light bounces off objects it hits, and then enters a proximity sensor. The output is then transformed into a voltage that can be fed into the ESP32 and read.

<img src="{{ '/_assets/images/ir-sensor-functionality.png' | prepend: site.baseurl }}" alt="ir-sensor-functionality.png">
<img src="{{ '/_assets/images/ir-sensor-graph.png' | prepend: site.baseurl }}" alt="ir-sensor-graph.png">

## Interfacing
There are 3 pins (red, black, white) to the device as seen in the top right picture, associated to Power, Ground, and Output Signal, respectively. For testing the distance sensor, let’s use the analog pin, pin 27,  as the signal pin. Hook up the circuit as follows.

<img src="{{ '/_assets/images/IR-sensor-wiring-diagram.png' | prepend: site.baseurl }}" alt="ir-sensor-wiring-diagram.png">

## Programming 
The following program will allow you to read values from the IR sensor in a loop. After you build and flash the program, you should see the values in the UART change as you move it towards and away from an object.

## Extensions
You received values from the sensor, but do they mean anything? The next step for the IR sensor is translating and thresholding it. Take a look at the above graph. There is a strong linear relationship between your signal value and the inverse of the distance away from the object. It’s your job now to code a function that returns an accurate distance given a voltage input value. After that, your team needs to threshold the data. When do the values become inconsistent (too close or too far)? What do you do with your robot when that happens?


