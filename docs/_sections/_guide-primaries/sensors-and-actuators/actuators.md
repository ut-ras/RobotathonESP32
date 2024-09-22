---
layout: default
title: Actuators
nav_include: true
parent: Sensors and Actuators
nav_order: 4
---

# Actuators

The word "actuators" is just a fancy word for "devices that create motion," which can include anything ranging from hydraulic pistons to motors. In our case, electric motors will be the key to your robot's motion! You will deal with two types electrical actuators in this competition: DC motors and servo motors.

# DC Motors
<img src="{{ '/_assets/images/dc_motor.jpg' | prepend: site.baseurl }}" alt="dc_motor.jpg" width="200" height="300">

You will be using DC (direct current) motors as the primary means of moving your robot around. However, directly connecting a DC motor to the ESP32 may not be desirable due to lack of direction control and higher voltage/current requirements of the motor. This is where motor controllers come into play.

## Motor Controllers
<img src="{{ '/_assets/images/l298n_motor_driver.jpg' | prepend: site.baseurl }}" alt="l298n_motor_driver.jpg" width="200" height="300">
<img src="{{ '/_assets/images/l298n_driver_pinout.png' | prepend: site.baseurl }}" alt="l298n_driver_pinout.png" width="300" height="400">

A motor controller, such as the L298N, acts as an intermediary between the microcontroller and the DC motor. It allows the microcontroller to control the motor's speed and direction without directly handling the high current. The motor controller has the following key components:
* H-Bridge Circuit: This allows the motor to be driven in both forward and reverse directions. Different combinations of IN1 and IN2 will determine the spin direction. 
* PWM (Pulse Width Modulation) Control: This allows speed control by varying the duty cycle of the PWM signal.
* Power Supply Terminals: These provide the necessary power to the motor.
* 5V Voltage Regulator: This allows the motor controller to act as a 5V output power supply. This functionality can be disabled by removing the corresponding jumper (see below)

The following information is an adapted version of [this guide.](https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/)

# How to Use Motor and Motor Controller?
First we will go over using an external power source for the ESP32. For this competition, you will be able to control your robot with a wireless game controller to navigate around the field (sensor challenges should be completed autonomously). It would be impractical to power your ESP32 through USB on the field, so you will use a battery pack. We need to reduce the voltage of the battery pack down to a level the ESP32 can safely use through the motor controller's 5V voltage regulator.

Here is a diagram of how your circuit should look when using the battery pack (voltage regulator jumper needs to be in place to enable the motor controller's 5V output to the ESP32):

<img src="{{ '/_assets/images/external_ESP32_power.png' | prepend: site.baseurl }}" alt="external_ESP32_power.png">
<img src="{{ '/_assets/images/motor_controller_jumper.png' | prepend: site.baseurl }}" alt="motor_controller_jumper.png" width=400 height=400>

If you want to power your ESP32 and motors while using a USB connection, simply remove one battery from the battery pack (creates open circuit) and take out the voltage regulator jumper on the motor controller (will make 5V terminal receive input). You should now be able use your USB connection safely!

{: .highlight}
Do NOT power your ESP32 through its 5V pin with the battery pack while simultaneously connecting it to your computer through USB! This may irreversibly damage your devices (only do one at a time).
{: .callout-toby}

To control a DC motor using the ESP32, a motor controller, and AA battery pack, you can connect them together as shown below:

<img src="{{ '/_assets/images/motor_with_external_power.png' | prepend: site.baseurl }}" alt="motor_with_external_power.png">

* You will need to remove the jumper shorting the ENA pin to 5V
* You will need to use a screwdriver to clamp the power wires in place (all the wires connecting to the blue screw terminals) into place. Make sure these are secure because wires coming loose and causing a short circuit could be catastrophic!
* Note that the wire polarity on the motor does not matter because DC motors' spin direction is based on the direction of current flowing through them.

<br>

|  Motor Controller Terminal   | ESP32 Pin          |
|:-------------|:------------------|
| 5V           | 5V                      |
| IN1          | Any GPIO      |
| IN2          | Any GPIO     |
| ENA          | Any PWM enabled pin      |

If you're not sure about the ESP32 pinout, then check out [this page!](https://ut-ras.github.io/RobotathonESP32/getting-started/microcontroller-interface)


The following is an example of configuring and running the motor in software:
```cpp

#include "sdkconfig.h"
#include <Arduino.h>

#define IN1  27  // Control pin 1
#define IN2  14  // Control pin 2
#define ENA  12  // PWM pin

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {
  // Spin motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);

  delay(1000);  // Run for 1 second

  // Stop motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  delay(1000); // Stop for 1 second
}
```
Again, more detailed information about the L298N motor controllers can be [found here!](https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/)

# Servo Motors

<img src="{{ '/_assets/images/servo.jpg' | prepend: site.baseurl }}" alt="servo.jpg" width="300" height="400">

## What Are Servos?

Servos are motors that are designed for precise position control. Instead of freely rotating when powered, servos listen to a control signal (usually [PWM](https://learn.sparkfun.com/tutorials/pulse-width-modulation/all)) to determine where to rotate. Some servos offer limited rotation, while others can rotate continuously (like ours).More advanced servos have other ways to be even more precise such as a feedback system on top of the control signal, but that is not necessary for this competition.

## How to Use Servos?

For the servos in our competition, you can use it to precisely control your mechanism for the Mechanical Challenge. To interface it with your ESP32, you will connect the wires as follows:

<img src="{{ '/_assets/images/servo_wiring.png' | prepend: site.baseurl }}" alt="servo_wiring.png">

| Servo Wire        | ESP32 Pin          |
|:-------------|:------------------|
| Red           | 5V                      |
| Black          | GND      |
| White        |  Any PWM capable pin          |

If you're not sure about the ESP32 pinout, then check out [this page!](https://ut-ras.github.io/RobotathonESP32/getting-started/microcontroller-interface)


In this competition, we will be using the Arduino servo library to control the servos. The following is an example of how to spin a servo using the ESP32's pin 2 as the PWM output.

```cpp
#include "sdkconfig.h"
#include <Arduino.h>

#include <ESP32Servo.h>

Servo myServo;

void setup() {
  myServo.attach(2);
  myServo.write(1750);
}

void loop() {

}
```

Simply input a different value in the ```write()``` function to change how the servo behaves! See [this official Arduino guide for more info](https://www.arduino.cc/reference/en/libraries/servo/write/)