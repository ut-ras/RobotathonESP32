---
layout: default
title: Environment Setup
nav_include: true
parent: Getting Started
nav_order: 5
---

Please reference the setup guide found in the [Robotathon Repo's readme!](https://github.com/ut-ras/RobotathonESP32)

## Programming goal
For this tutorial, we will control the onboard microcontroller by toggling it on and off periodically. This will serve as the goal for the Blink Checkpoint and demonstrates that you can flash your own program to the ESP32. If you are having trouble configuring your development environment, reference the setup guide on our [Github (scroll down)](https://github.com/ut-ras/RobotathonESP32) or ask a mentor for help!

Once your environment is set up, you should be able to flash the program to your ESP32 by 
1. Copying it into the ```arduino_main.cpp``` file
1. Pressing the fire icon (build + flash) in VSCode's bottom ribbon 
1. Holding the BOOT button on the ESP32 (button to the right of the USB port that puts it into flashing mode) 
1. Waiting until the Serial Monitor shows up

The following program will blink the onboard LED (pin 2) on the ESP32 every second:

{: .highlight}
Note: While it is good coding practice to leave comments in your code to make it more understandable, they should be used sparingly to explain complex code — the below example has many comments for the sake of explanation.
{: .callout-toby}

```cpp
#include "sdkconfig.h"
#include <Arduino.h>

#define LED_BUILTIN 2; // defines the word "LED_BUILTIN" as the number 2 for ease of use/readability when using the pin later

void setup() {
    pinMode(LED_BUILTIN, OUTPUT); // configures pin 2 to be a GPIO output pin 
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH); // writes a digital high to pin 2
    delay(1000); // waits for 1000 milliseconds (1 second)
    digitalWrite(LED_BUILTIN, LOW); // writes a digital low to pin 2
    delay(1000);
}
```



