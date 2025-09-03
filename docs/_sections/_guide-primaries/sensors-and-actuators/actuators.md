---
layout: default
title: Actuators
nav_include: true
parent: Hardware
nav_order: 5
---

# Actuators

The word "actuators" is just a fancy word for "devices that create motion," which can include anything ranging from hydraulic pistons to motors. In our case, electric motors will be the key to your robot's motion! In this competition, you will be dealing with servo motors.


# DC Motors
<img src="{{ '/_assets/images/dc_motor.jpg' | prepend: site.baseurl }}" alt="dc_motor.jpg" width="200" height="300">

You will be using DC (direct current) motors as the primary means of moving your robot around. 


DC motors operate on electromagnetic principles. Inside the motor, there are permanent magnets (stator) that create a stationary magnetic field, and wire coils (rotor/armature) that carry electrical current. When current flows through the rotor windings in the presence of the magnetic field, electromagnetic forces cause the rotor to spin. A commutator and brushes automatically switch the current direction in the windings as the motor rotates, ensuring continuous rotation.

The motor’s speed depends on the applied voltage; higher voltage makes the motor spin faster. The torque (rotational force) depends on the current; more current allows the motor to push harder, such as when moving a heavier robot. Motor speed is controlled by pulse-width modulation ([PWM](https://learn.sparkfun.com/tutorials/pulse-width-modulation/all)), which is when the supply voltage is switched on and off rapidly. By adjusting the ratio of “on” to “off” time, you can smoothly control the average voltage the motor receives. Direction is reversed by by switching the voltage polarity.

However, directly connecting a DC motor to the ESP32 is not desirable due to lack of direction control and higher voltage/current requirements of the motor. This is where motor controllers come into play.  

## Motor Controllers
<img src="{{ '/_assets/images/DRV8833.png' | prepend: site.baseurl }}" alt="l298n_motor_driver.jpg" width="200" height="300">
<img src="{{ '/_assets/images/DRV8833_Pinout.png' | prepend: site.baseurl }}" alt="l298n_driver_pinout.png" width="300" height="400">

A motor controller, such as the DRV8833, acts as an intermediary between the microcontroller and the DC motor. It allows the microcontroller to control the motor's speed and direction without directly handling the high current. The motor controller has an H-bridge circuit, which allows different combinations of IN1 and IN2 to change the motor direction.

The following information is an adapted version of [this guide.](https://lastminuteengineers.com/drv8833-arduino-tutorial/)

# How to Use Motor and Motor Controller?

## Portable Battery Pack Power
First we will go over using an external power source for the ESP32. For this competition, you will be able to control your robot with a wireless game controller to navigate around the field (sensor challenges should be completed autonomously). It would be impractical to power your ESP32 through the on-board USB on the field, so you will use a portable battery pack. This battery pack will be connected using a USB-C 5V breakout board, which ensures the pack provides a steady 5V supply for your ESP32 and motor controller.

To safely power your ESP32 from the battery pack and still have the option to connect it to your laptop to use the serial monitor for debugging, add a diode between the breadboard's power line and the ESP32’s 5V pin. The diode works like a one-way valve, so it prevents current from accidentally flowing back into your computer or battery pack. Without the diode, you could risk frying your equipment!

Here is a diagram of how your circuit should look:

<img src="{{ '/_assets/images/DRV8833BatteryPack.png' | prepend: site.baseurl }}" alt="external_ESP32_power.png">

With this wiring, you can safely use both the battery pack and the USB connection!

{: .highlight}
ALWAYS use a diode on the ESP32’s 5V line when powering it from a battery pack.  
This prevents current from flowing back into your computer or battery pack if USB is also connected.
{: .callout-blue}

To control a DC motor using the ESP32, a motor controller, and battery pack (**WITH or WITHOUT USB CONNECTION**), you can connect them together as shown below:

<img src="{{ '/_assets/images/DRV8833withDCMotor.png' | prepend: site.baseurl }}" alt="motor_with_external_power.png">

* Note that the wire polarity on the motor does not matter because DC motors' spin direction is based on the direction of current flowing through them.

<br>

|  Motor Controller Terminal   | ESP32 Pin          |
|:-------------|:------------------|
| 5V           | 5V                      |
| IN1          | Any PWM enabled pin      |
| IN2          | Any PWM enabled pin     |

If you're not sure about the ESP32 pinout, then check out [this page!](https://ut-ras.github.io/RobotathonESP32/getting-started/microcontroller-interface)


The following is an example of configuring and running the motor in software:
```cpp

#include "sdkconfig.h"
#include <Arduino.h>

#define IN1  16  // Control pin 1
#define IN2  17  // Control pin 2

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // Spin motor
  analogWrite(IN1, 255);  // PWM signal
  digitalWrite(IN2, LOW); // Direction control

  delay(1000);  // Run for 1 second

  // Stop motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  delay(1000); // Stop for 1 second
}
```
Again, more detailed information about the DRV8833 motor controllers can be [found here!](https://lastminuteengineers.com/drv8833-arduino-tutorial/)

# Servo Motors

<img src="{{ '/_assets/images/servo.jpg' | prepend: site.baseurl }}" alt="servo.jpg" width="300" height="400">

## What Are Servos?

Servos are motors that are designed for precise position control. Instead of freely rotating when powered, servos listen to a control signal (usually [PWM](https://learn.sparkfun.com/tutorials/pulse-width-modulation/all)) to determine where to rotate. Some servos offer limited rotation (like 0°–180°), while others can rotate continuously (like ours). More advanced servos have other ways to be even more precise such as a feedback system on top of the control signal, but that is not necessary for this competition.

## How to Use Servos?

For the servos in our competition, you can use it to precisely control your mechanism for the Mechanical Challenge. To interface it with your ESP32, you will connect the wires as follows:

<img src="{{ '/_assets/images/DRV8833Servo.png' | prepend: site.baseurl }}" alt="servo_wiring.png">

The Red wire is connected to 5V from the battery pack.

| Servo Wire        | ESP32 Pin          |
|:-------------|:------------------|
| Black          | GND      |
| White        |  Any PWM enabled pin          |

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

Simply input a different value in the ```write()``` function to change how the servo behaves!