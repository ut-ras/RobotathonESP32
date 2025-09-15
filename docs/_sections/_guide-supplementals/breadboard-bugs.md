<!-- ---
layout: default
title: Debugging
nav_include: true
# parent: Resources
nav_order: 2
--- -->

<!-- TODO add to this section and maybe remove the bottom "How to avoid a short circuit bc its kinda useless for the comp. if anything just integrate some of the tips into hardware bugs? -->

# Debugging

Things aren't working? Chances are it's because of something super silly like an unplugged wire or off by one error.

## Software Bugs

1. Do you have any unintentional infinite loops?
1. Are you calling `vTaskDelay(1)` in your main loop to reset the watchdog timer? (included in sample code)
1.


## Hardware Bugs

<!-- TODO finish checklist -->
1. Is everything plugged in properly?
    * Did you double check?
1. If the issue is with your color sensor, did you have the SDA and SCL lines flipped?
1. Did you try using a multimeter to diagnose the issue?
1. Did you try another sensor if the current one you are trying doesn't work?

### What is a short circuit?

A short circuit is the connection between two different nodes that are at different voltages via  a path of very low resistance. 

### Why Should You Avoid a Short Circuit?
A short circuit causes a surge of high amounts of current to flow through both nodes, which is very dangerous. This could cause potential injuries such as a shock or a burn as well as damage electronics nearby.  Hence why it is preferable to avoid shorting anything.

### How to Avoid a Short Circuit:
* Disconnect power from any electronic device when interfacing with its hardware.
 * Do not have microcontroller connected to power when moving around cables
* Make sure that there are no open cables  near an electronic device with power.
* Make sure to not connect cables to the wrong pins.
 * i.e. you should never directly connect VCC to GND with no resistance in between. 
* Make sure to connect resistors of the necessary resistance to any electronic devices you will interface with.
 * Not doing so will a high amount of current through the electronic device and potentially damage it (or make it burst into flames)
* Don’t touch an electronic part with a metal
 * Avoid having any type of metal near electronic devices
* Make sure that all cables are safely connected and cannot disconnect when the device is in use. 
* When soldering electronics, make sure that solder does not cover two pins at once, or be somewhere it’s not supposed to. 
* Don’t be distracted when working with electricity.

