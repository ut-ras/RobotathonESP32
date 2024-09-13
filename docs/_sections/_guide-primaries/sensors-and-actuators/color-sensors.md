---
layout: default
title: Color Sensor
nav_include: true
parent: Sensors and Actuators
nav_order: 1
---

# Color Sensor UNEDITED
The TCS34725 ordered from Adafruit will allow you to navigate the Dance Challenge. By sensing the color of the tile you are on, your robot can waltz across the dance floor to victory, racking up those sweet combos!

## How it Works
The RGB sensor uses the RGB color space to represent the color that it sees. In our case, it provides the data in integer values of 0-255, represented in 8 binary bits. We will grab that data using a communication protocol called I2C, which is used in many electrical devices. The specific I2C implementation is found in RASware, but we’ve abstracted the hard logic for you already.

# INSERT DIAGRAM OF WIRED EXAMPLE HERE

## Programming
For this tutorial, we’re only going to be reading the RGB sensor values from the TCS34725. Make sure that your pins are correctly connected or otherwise you won’t receive the data!
Build and flash the program, and watch the output change as you hold the sensor to different colored objects!

# Extensions
Extensions
Now that you’ve completed this tutorial, let’s move to more advanced stuff!
For the checkpoint I’m Sorry, You May Be Color Blind, you need to classify various colors. Try to output a specific message on CLI when you read Red or Blue or other colors.
Try to threshold a level of error for your sensor and think about the following questions. 
* Do the values change under different lighting? 
* Different distances? 
* What about various shades of red? Is red one specific RGB value?
If you have a moving base, try to drive in a certain direction based on color. How about going right on a red tile?

<img src="{{ '/_assets/images/color_sensor_wiring.png' | prepend: site.baseurl }}" alt="color_sensor_wiring.png">
<img src="{{ '/_assets/images/color_sensor.jpg' | prepend: site.baseurl }}" alt="color_sensor.jpg">

todo make the color sensor picture a lot smaller lol