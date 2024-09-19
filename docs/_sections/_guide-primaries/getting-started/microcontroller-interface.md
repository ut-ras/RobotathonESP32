---
layout: default
title: Microcontroller Interfacing
nav_include: true
parent: Getting Started
nav_order: 4
---

# Microcontroller Interfacing
Microcontrollers are cool and all, but they’re a lot more interesting when you can use them to do stuff in the real world! You can connect all sorts of devices to the ESP32 microcontroller to do whatever your heart desires. Below is a picture of that describes what kinds of connections can be made with each pin:

<img src="{{ '/_assets/images/wroom_pinout.jpg' | prepend: site.baseurl }}" alt="wroom_pinout.jpg">

We are only concerned with pins that are power, ground, GPIO, and ADC enabled, so don't worry about all the extra features. 

* Power - 3V3 and 5V pins labeled with red. These pins will always be outputting their respective voltage levels (3.3V and 5V) if the ESP32 is powered through its USB-micro port.
* Ground - pins labeled as GND. These pins serve as the current's return path in your circuits.
* GPIO (General Purpose Input/Output) - virtually every pin. These pins can be configured to read or output digital high and low signals.
* ADC (Analog to Digital Converter) - only some pins. These pins can read analog values instead of just high or low. 

{: .highlight}
Note: Do NOT short (connect) a power pin directly to a ground pin. This will likely fry your ESP32 by causing a huge surge of current. 
{: .callout-toby}

For this competition, you will be able to control your robot with a wireless game controller. 

It would be impractical to power your ESP32 through your laptop with a super long cable, so you will use a battery pack feeding through a buck converter to power the 5V pin of the ESP32.

<img src="{{ '/_assets/images/buck_converter.png' | prepend: site.baseurl }}" alt="buck_converter.png" width=400 height=400>

You will use this buck converter to reduce the voltage of the battery pack down to a level the ESP32 can tolerate (5V). Here are the steps to interface the battery pack to the ESP32 (assumes ESP32 is seated in breadboard):

 1.) Connect the red wire from the battery pack to the IN+ on the buck converter and the black wire from the battery pack to the IN- on the buck converter

 2.) Grab a multimeter, put it into voltage reading mode, and attach the leads to OUT+ and OUT-. Rotate the small yellow screw on the buck converter counterclockwise until the multimeter reads a voltage of 5V.

 3.) Remove the multimeter leads and attach a red wire from the buck converter's OUT+ terminal to the ESP32's 5V pin. Attach a black wire from the buck converter's OUT- terminal to the ESP32's GND pin.

 (((insert picture of wire diagram here)))

{: .highlight}
Note: Do NOT power your ESP32 through its 5V pin using the battery pack while simultaneously connecting it to your computer!! This may seriously damage either of your devices (please only do one at a time).
{: .callout-toby}

If you want to know more about any features, feel free to ask a mentor or Google for more information :) 





