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

The USB connection to your computer is necessary for uploading and debugging your code through the serial monitor. It would be easiest to keep using the USB connection until later in the competition when testing the full system.

{: .highlight}
Note: Do NOT power your ESP32 through its 5V pin with the battery pack while simultaneously connecting it to your computer! This may irreversibly damage your devices (only do one power connection at a time).
{: .callout-toby}

<!-- Using the external battery pack is detailed in the [Actuators page](https://ut-ras.github.io/RobotathonESP32/sensors-and-actuators/actuators) because we will be using the motor driver's 5V output to power the ESP32. -->

<img src="{{ '/_assets/images/buck_converter_power.png' | prepend: site.baseurl }}" alt="buck_converter_power.png">

First we will go over using an external power source for the ESP32. For this competition, you will be able to control your robot with a wireless game controller to navigate around the field (sensor challenges should be completed autonomously). It would be impractical to power your ESP32 through USB-laptop connection on the field, so you will need a battery pack. We need to reduce the voltage of the battery pack down to a level the ESP32 can safely use through the buck converter.

If you want to power your ESP32 and motors while using a USB connection, simply **securely** place one of the battery leads to an unused row in your breadboard (like picture below).

<img src="{{ '/_assets/images/buck_converter_disable.png' | prepend: site.baseurl }}" alt="buck_converter_disable.png">

You should now be able use your USB connection safely!

If you want to know more about any features, feel free to ask a mentor or Google for more information :) 






