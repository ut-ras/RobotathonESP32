---
layout: default
title: Microcontroller Interfacing
nav_include: true
parent: Getting Started
nav_order: 4
---

# Microcontroller Interfacing KINDA OUTDATED, images need formatting
Microcontrollers are cool and all, but they’re a lot more interesting when you can do stuff in the real world!

## Programming goal
For this tutorial, we want to turn on the LED if: PA2 is turned high (to power the LED) and the switch is closed. The example code can be found in our github.

## Interfacing example
For this example, we’ll use an LED and a switch. You will need six components - a red LED, switch, 470 ohm resistor, TM4C, breadboard, and some wires. 

{: .highlight}
Our microcontroller pin outputs way too much current for our LED to handle, so we need to put a resistor in series with the microcontroller output pin and LED.
{: .callout-toby}

1. Connect a wire to a GPIO pin (let’s choose PA2 for this example). The other end goes to one of the switch legs.
1. Stick the long side of the LED on another switch leg. Use the continuity mode on the multimeter to make sure the leg is disconnected by putting each of the probes at each end of the switch (see below). Pressing the switch should short the legs.
1. Put the resistor in series with the short end of the LED (-), and connect the GND pin to the other end of the resistor.

<img src="{{ '/_assets/images/led-pinout.png' | prepend: site.baseurl }}" alt="led interface :()" width=550 height=235>

<img src="{{ '/_assets/images/outdated-circuit-diagram.png' | prepend: site.baseurl }}" alt="outdated-circuit-diagram :()">

<img src="{{ '/_assets/images/button-diagram.png' | prepend: site.baseurl }}" alt="led interface">

<img src="{{ '/_assets/images/continuity-test.png' | prepend: site.baseurl }}" alt="led interface">