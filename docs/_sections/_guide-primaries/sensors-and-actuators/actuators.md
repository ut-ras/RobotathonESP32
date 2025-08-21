---
layout: default
title: Actuators
nav_include: true
parent: Hardware
nav_order: 5
---

# TODO: elaborate more on how servos and DC motors actually work

# Actuators

The word "actuators" is just a fancy word for "devices that create motion," which can include anything ranging from hydraulic pistons to motors. In our case, electric motors will be the key to your robot's motion! In this competition, you will be dealing with servo motors.


# DC Motors
<img src="{{ '/_assets/images/dc_motor.jpg' | prepend: site.baseurl }}" alt="dc_motor.jpg" width="200" height="300">

You will be using DC (direct current) motors as the primary means of moving your robot around. 


DC motors operate on electromagnetic principles. Inside the motor, there are permanent magnets (stator) that create a stationary magnetic field, and wire coils (rotor/armature) that carry electrical current. When current flows through the rotor windings in the presence of the magnetic field, electromagnetic forces cause the rotor to spin. A commutator and brushes automatically switch the current direction in the windings as the motor rotates, ensuring continuous rotation.

The motor's speed is controlled by varying the applied voltage (typically using PWM), while direction is reversed by switching the voltage polarity.

However, directly connecting a DC motor to the ESP32 is not desirable due to lack of direction control and higher voltage/current requirements of the motor. This is where motor controllers come into play.  

## Motor Controllers
<img src="{{ '/_assets/images/DRV8833.png' | prepend: site.baseurl }}" alt="l298n_motor_driver.jpg" width="200" height="300">
<img src="{{ '/_assets/images/DRV8833_Pinout.png' | prepend: site.baseurl }}" alt="l298n_driver_pinout.png" width="300" height="400">

A motor controller, such as the DRV8833, acts as an intermediary between the microcontroller and the DC motor. It allows the microcontroller to control the motor's speed and direction without directly handling the high current. The motor controller has an H-bridge circuit, which allows different combinations of IN1 and IN2 to change the motor direction.

The following information is an adapted version of [this guide.](https://lastminuteengineers.com/drv8833-arduino-tutorial/)

# How to Use Motor and Motor Controller?

## Portable Battery Pack Power
First we will go over using an external power source for the ESP32. For this competition, you will be able to control your robot with a wireless game controller to navigate around the field (sensor challenges should be completed autonomously). It would be impractical to power your ESP32 through the on-board USB on the field, so you will use a portable battery pack. 

Here is a diagram of how your circuit should look when using the portable battery pack:

<img src="{{ '/_assets/images/Power_from_power_bank.png' | prepend: site.baseurl }}" alt="external_ESP32_power.png">

However, if you want to be able to use your motors and plug your ESP32 into your laptop to use the serial monitor for debugging, then you'll have to change the wiring (or else you will fry your equipment!):

<img src="{{ '/_assets/images/Power_from_microUSB.png' | prepend: site.baseurl }}" alt="motor_controller_with_usb.png">

You should now be able use your USB connection safely!

{: .highlight}
Do NOT power your ESP32 through its 5V pin with the battery pack while simultaneously connecting it to your computer through USB! This may irreversibly damage your devices (only do one at a time).
{: .callout-blue}

To control a DC motor using the ESP32, a motor controller, and battery pack (**WITH USB CONNECTION**), you can connect them together as shown below:

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

Servos are motors that are designed for precise position control. Instead of freely rotating when powered, servos listen to a control signal (usually [PWM](https://learn.sparkfun.com/tutorials/pulse-width-modulation/all)) to determine where to rotate. Some servos offer limited rotation, while others can rotate continuously (like ours). More advanced servos have other ways to be even more precise such as a feedback system on top of the control signal, but that is not necessary for this competition.

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

Simply input a different value in the ```write()``` function to change how the servo behaves!