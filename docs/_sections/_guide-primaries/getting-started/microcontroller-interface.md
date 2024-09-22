---
layout: default
title: Microcontroller Interfacing
nav_include: true
parent: Getting Started
nav_order: 4
---

# Microcontroller Interfacing
Microcontrollers are cool and all, but they’re a lot more interesting when you can use them to do stuff in the real world! You can connect all sorts of devices to the ESP32 microcontroller to do whatever your heart desires.

Below is a picture of that describes what kinds of connections can be made with each pin:

<img src="{{ '/_assets/images/wroom_pinout.jpg' | prepend: site.baseurl }}" alt="wroom_pinout.jpg">

We are only concerned with pins that are power, ground, GPIO, and ADC enabled, so don't worry about all the extra features. 

* Power - 3V3 and 5V pins labeled with red. These pins will always be outputting their respective voltage levels (3.3V and 5V) if the ESP32 is powered through its USB-micro port.
* Ground - pins labeled as GND. These pins serve as the current's return path in your circuits.
* GPIO (General Purpose Input/Output) - virtually every pin. These pins can be configured to read or output digital high and low signals.
* ADC (Analog to Digital Converter) - only some pins. These pins can read analog values instead of just high or low. 

{: .highlight}
Warning: Be careful to not short (connect) a power pin directly to a ground pin. This will fry your ESP32 and more by causing a huge surge of current. 
{: .callout-toby}

## Powering the ESP32
You can power your ESP32 by 2 methods: USB connection or external battery pack.

The USB connection to your computer is necessary for uploading and debugging your code through the serial monitor. It would be easiest to keep using the USB connection until later in the competition when testing the entire system.

{: .highlight}
Note: Do NOT power your ESP32 through its 5V pin with the battery pack while simultaneously connecting it to your computer! This may irreversibly damage your devices (only do one at a time).
{: .callout-toby}

Using the external battery pack is detailed in the [Actuators page](https://ut-ras.github.io/RobotathonESP32/sensors-and-actuators/actuators) because we will be using the motor driver's 5V output to power the ESP32.

If you want to know more about any features, feel free to ask a mentor or Google for more information :) 






