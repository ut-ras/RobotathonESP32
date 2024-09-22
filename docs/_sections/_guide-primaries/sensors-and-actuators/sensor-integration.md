---
layout: default
title: Sensor Integration
nav_include: true
parent: Sensors and Actuators
nav_order: 5
---

# Sensor Integration

Help! How do we put everything together?
Now that you’ve completed several checkpoints and have probably gone through the interfacing tutorials, you and your team are probably wondering how to put all these various parts together. How do we merge RGB sensor data with motor movement? What happens when you encounter a nonexistent wall with your distance sensors?

Unfortunately, there are no easy answers to these questions. Your best bet is to experiment with your intuitions. An example is moving along a curved line. A starting series of intuitions could be:

* I want to keep my robot centered on the line.
* My line sensor should probably also be centered on the line.
* If my middle line sensors are thresholding a line, and my side line sensors aren’t, then I am probably centered on the line.
* If not, then I am off the line and should correct slightly by:
 * Driving one wheel faster than the other.
 * Stopping and rotating the robot until I find the line again.
 * Etcetera …

Test each intuition to see if it makes sense! Eventually, your intuitions will build a representative model of the world and how to traverse it.  This is important because a great deal of robotics revolves around this concept. Think about autonomous cars. They need to build an internal world replete with virtual pedestrians, vehicles, stop signs, and more, as well as make decisions based on encountering them.

Building and acting upon your model of the world can be hard. We encourage partitioning your code into three states or events. A simple example is provided below.

1. The IR sensors says that there is a wall to your front and left.
1. Update the robot’s memory of the maze with these newfound walls.
1. Since there is a wall to the front and the left, let’s turn right with our motors.

We leave the implementation of the example as an exercise for the reader.
Finally, we would also like to emphasize writing clean and readable code. Clean code helps both your team and the mentors by making it easier to debug.

A coding convention guide can be found (here!)[http://www.cs.umd.edu/~nelson/classes/resources/cstyleguide/]

# Extensions
* How will your robot cope with multiple challenges?
* How will you reset your robot after completing a challenge?
* What if you receive sensor data that you’ve not encountered before?
