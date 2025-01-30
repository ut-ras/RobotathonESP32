---
layout: default
title: Bluetooth Controller
nav_include: true
parent: Getting Started
nav_order: 6
---

# Bluetooth Controller

The purpose of the remote controller is to allow manual control of your robot for triggering your autonomous modes, moving between challenges, and firing your launching mechanism.

That being said, you will not be allowed to manually drive your robot through the challenges, as that defeats the purpose of having the sensors

It is highly recommended that you program specific functions of the sensors (line, color, distance) to specific buttons on the remote controller so that you have more control over your robot's behavior (i.e. press A -> color sensing mode).



## How do I find out what my controller’s Bluetooth address is?
1. Plug in your ESP32 and flash it with the starter code in your forked repository if you haven't already
1. Open the serial monitor
1. You should see this in the serial monitor while trying to connect your controller:
<img src="{{ '/_assets/images/controller_address.png' | prepend: site.baseurl }}" alt="controller_address :(">
The string of octets (something like “98:B6:E1:7C:C3:95”) is your controller’s Bluetooth address

## How do I connect my controller?
1. Make sure you have added your controller’s Bluetooth address to the ESP32 ([How do I do that?](TODO WRITE THIS))
1. Power and flash ESP32 with starter code
1. Press and hold the home button on your controller (big H button in the middle) until the lights turn on and then speed up
1. Controller should connect automatically



