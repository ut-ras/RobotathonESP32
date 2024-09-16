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

The following program will blink the onboard LED (pin 2) on the ESP32 every second:

{: .highlight}
Note: While it is good coding practice to leave comments in your code to make it more understandable, they should be used sparingly to explain complex code — the below example has a ton of comments for the sake of explanation.
{: .callout-toby}

```cpp
int LED_BUILTIN = 2; // defines the word "LED_BUILTIN" as the number 2 for ease of use when defining and using the pin later

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



