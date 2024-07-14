---
layout: default
title: Sensor and Actuator Placement
nav_include: true
parent: Designing a Robot
nav_order: 1
---

# Sensor and Actuator Placement

You will need to carefully plan your sensor and actuator placement as it will drastically shape your robot! This section will give a brief overview of some things to consider during this part of the design process.

## Infrared (IR) Distance Sensor
The distance sensor will be used during the wall following portion of the competition. The location of the distance sensors *will* affect your chassis design and code, so it is important to decide on a good location! Also remember that you will have multiple IR sensors in your design.

{: .highlight}
Remember that the GP2Y0A21YK0F IR sensors have a specific range [(link to datasheet)](https://www.pololu.com/file/0J85/gp2y0a21yk0f.pdf) that produces good output, so make sure your placement does not break your wall following! One way to avoid the sensor getting too close to the wall could be to move them closer to the middle of the chassis.
{: .callout-toby}

Below are some different ideas of placement:
<img src="{{ '/_assets/images/IR_sensors.png' | prepend: site.baseurl }}" alt="IR_sensors.png :(">

## Line Sensor and Color Sensor
These two sensors will have similar placement! The line sensor and color sensor will be used to to detect what is right underneath the robot so these two will be placed on the bottom of your robot. Make sure your sensors are very close to the ground in order for them to function properly!

However, a common issue with the color sensor is that there is not enough neutral (white) light to get an accurate reading. One way to get around this is to use a white LED to illuminate the area to be scanned.

Since your sensors need to be very close to the ground you should consider how you will be building the chassis of your robot and how you will attach these sensors. Your wheels will add some height to your chassis so you might have to add some form of support to the bottom in order to hold your sensors close to the ground.

Illustrated below is a sample configuration:

<img src="{{ '/_assets/images/line_and_color.png' | prepend: site.baseurl }}" alt="line_and_color.png :(" >

## Actuators
"Actuators" is just a fancy name for motors or anything that enables some kind of movement for your robot. You will need at least two of these with a castor ball to have a moving base. While you have full creative reign on where to put your actuators to achieve motion and solve the mechanical challenge, it will be important to consider where to place your wheel actuators since they will affect how your robot drives and, (arguably) most importantly, turns.

