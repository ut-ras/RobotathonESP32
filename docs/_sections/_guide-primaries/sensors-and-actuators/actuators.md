---
layout: default
title: Actuators
nav_include: true
parent: Sensors and Actuators
nav_order: 5
---

# Actuators

The word "actuators" is just a fancy word for "devices that create motion," which can include anything ranging from hydraulic pistons to motors. In our case, electric motors will be the key to your robot's motion! You will deal with two types electrical actuators in this competition: DC motors and servo motors.

# DC Motors
<img src="{{ '/_assets/images/dc_motor.jpg' | prepend: site.baseurl }}" alt="dc_motor.jpg" width="200" height="300">

You will be using DC (direct current) motors as the primary means of moving your robot around. However, directly connecting a DC motor to the ESP32 may not be desirable due to lack of direction control and higher voltage/current requirements of the motor. This is where motor controllers come into play.

## Motor Controllers
<img src="{{ '/_assets/images/l298n_motor_driver.jpg' | prepend: site.baseurl }}" alt="l298n_motor_driver.jpg" width="200" height="300">

A motor controller, such as the L298N, acts as an intermediary between the microcontroller and the DC motor. It allows the microcontroller to control the motor's speed and direction without directly handling the high current. The motor controller typically has the following key components:
* H-Bridge Circuit: This allows the motor to be driven in both forward and reverse directions.
* PWM (Pulse Width Modulation) Control: This enables speed control by varying the duty cycle of the PWM signal.
* Power Supply Terminals: These provide the necessary power to the motor.

The following information is an adapted version of [this guide.](https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/)

# How to Use Motor and Controller?
To control a DC motor using an ESP32 and a motor controller, you need to directly connect the power source and ESP32 to the motor controller as shown below:
<br>
<img src="{{ '/_assets/images/l298n_driver_pinout.png' | prepend: site.baseurl }}" alt="l298n_driver_pinout.png" width="300" height="400">

Motor Controller Power: Connect the motor controller's 12V terminal to a power source less than 12V
Motor Power: Connect the motor leads into the terminals with 2 slots. Polarity (order of red and black wires) do not matter because DC motors are designed to run either direction based on the current direction running through them.
Control Pins: Connect the control pins (e.g., IN1, IN2, ENA) on the motor controller to the GPIO pins on the ESP32.
<br>

| Motor Wire        | Motor Controller Terminal          |
|:-------------|:------------------|
| Red           | OUT1                      |
| Black          | OUT2       |

|  Motor Controller Terminal   | ESP32 Pin          |
|:-------------|:------------------|
| +5V           | 5V                      |
| IN1          | Any GPIO      |
| IN2          | Any GPIO     |
| ENA          | Any PWM enabled pin      |

The following is an example of configuring and running the motor in software:
```cpp

#include "sdkconfig.h"
#include <Arduino.h>

#define IN1  27  // Control pin 1
#define IN2  26  // Control pin 2
#define ENA  25  // PWM pin

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
More detailed information about the L298N motor controllers can be [found here!](https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/)

# Servo Motors

<img src="{{ '/_assets/images/servo.jpg' | prepend: site.baseurl }}" alt="servo.jpg" width="300" height="400">

## What Are Servos?

Servos are motors that are designed for precise position control. Instead of freely rotating when powered, servos listen to a control signal (usually [PWM](https://learn.sparkfun.com/tutorials/pulse-width-modulation/all)) to determine where to rotate. Some servos offer limited rotation, while others can rotate continuously (like ours).More advanced servos have other ways to be even more precise such as a feedback system on top of the control signal, but that is not necessary for this competition.

## How to Use Servos?

For the servos in our competition, you can use it to precisely control your mechanism for the Mechanical Challenge. To interface it with your ESP32, you will connect the wires as follows:

| Servo Wire        | ESP32 Pin          |
|:-------------|:------------------|
| Red           | 5V                      |
| Black          | GND      |
| White        |  Any PWM capable pin          |

{: .highlight}
If you're not sure which ESP32 pins are hardware PWM capable, then check out the diagram in [this page!](https://ut-ras.github.io/RobotathonESP32/getting-started/microcontroller-interface)
{: .callout-toby}

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