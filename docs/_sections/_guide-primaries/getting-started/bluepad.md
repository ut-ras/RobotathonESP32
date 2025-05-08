---
layout: default
title: Bluetooth Controller
nav_include: true
parent: Getting Started
nav_order: 6
---

# Bluetooth Controller

You will be connecting a game controller to your ESP32 for controlling your robot (i.e. triggering autonomous modes, moving between challenges, and firing your launching mechanism)

That being said, you will not be allowed to manually drive your robot through the challenges, as that defeats the purpose of having the sensors.

It is highly recommended that you program specific functions of the sensors (line, color, distance) to specific buttons on the remote controller so that you have more control over your robot's behavior (i.e. press A -> color autonomy mode, press B -> exit to normal drive mode).

## Connecting the Controller

See [BluePad32's official docs](https://bluepad32.readthedocs.io/en/latest/FAQ/#:~:text=true%3B%0A%7D-,Using%20allowlist%20commands%20from%20the%20USB%20console,%C2%B6,-Note) if you'd like to see other features.


First you will need to find out what your controller's Bluetooth address is.
1. Plug in your ESP32 and flash it with the starter code
1. Open the serial monitor
1. You should see this in the serial monitor while trying to connect your controller (press and hold power button on controller until lights slowly and then rapidly move):
<img src="{{ '/_assets/images/controller_address.png' | prepend: site.baseurl }}" alt="controller_address :(">
The string of octets (something like `98:B6:E1:7C:C3:95`) is your controller’s Bluetooth address

1. Try adding your controller's Bluetooth address through the serial terminal:
<img src="{{ '/_assets/images/add_bluetooth.png' | prepend: site.baseurl }}" alt="add_bluetooth.png :(">

1. Controller should connect automatically, and the controller data should begin streaming in the serial monitor

## Using the Controller

- BP32.update()
- for loop in loop()
    - todo: actually figure out how the iterator works and make it something more standard to be understandable by anyone

- accessing controller data




