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

We are only concerned with pins that are power, ground, GPIO, and ADC enabled, so don't worry about all the extra abilities. 

* Power - 3V3 and 5V pins labeled with red. These pins will always be outputting their respective voltage levels (3.3V and 5V) as long as the ESP32 is powered
* Ground - pins labeled as GND. These pins are 0V and serve as the return path in your circuits.
* GPIO (General Purpose Input/Output) - virtually every pin. These pins can be configured to read or output digital high and low signals.
* ADC (Analog to Digital Converter) - only some pins. These pins can read analog values instead of just high or low. 

{: .highlight}
Note: Do NOT short (connect) a power pin directly to a ground pin. This will likely fry your ESP32 by causing a huge surge of current. 
{: .callout-toby}

If you want to know more about any features, feel free to ask a mentor or Google for more information :) 





