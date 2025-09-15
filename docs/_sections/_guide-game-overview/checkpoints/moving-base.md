---
layout: default
title: Moving Base
nav_include: true
parent: Checkpoints
nav_order: 4
---

# Moving Base Checkpoint
To pass this checkpoint, your robot should meet the following requirements:

* Motors attached to a chassis
* Robot chassis moves when given controller input (i.e. pushing joystick moves forward, letting go stops)


Next Steps:
* Use CADed materials for your chassis (laser-cut for main chassis, 3D-print for other parts recommended)
* Be able to control your robot more precisely with the controller (turn left, right, back, forward)
* Be able to change your robot's mode when you press a button
    * For example, an easy way to organize your robot's functionality would have a default drive mode where you can easily switch between sensor modes as shown below:
    

Some questions we might ask you:
* How is your robot powered?
* Why do we recommend using a diode to feed power into the ESP32 5V pin?
* How does the ESP32 control the motors?
* How does passing DC through these motors create torque?
* How do H-bridge motor drivers work?