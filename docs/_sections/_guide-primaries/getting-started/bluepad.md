---
layout: default
title: Bluetooth Controller
nav_include: true
parent: Getting Started
nav_order: 6
---

# Bluetooth Controller

You will be connecting a wireless game controller to your ESP32 for controlling your robot (i.e. triggering autonomous modes, moving between challenges, and firing your launching mechanism)

That being said, you will not earn points for manually driving your robot through the challenges, as that defeats the purpose of having the sensors.

It is highly recommended that you map autonomous sensors modes (line, color, distance) to specific buttons on the remote controller so that you have more control over your robot's behavior (i.e. press A -> autonomous color mode, press B -> exit to normal drive mode).

## Connecting the Controller

See [BluePad32's official docs](https://bluepad32.readthedocs.io/en/latest/FAQ/#:~:text=true%3B%0A%7D-,Using%20allowlist%20commands%20from%20the%20USB%20console,%C2%B6,-Note) if you'd like to see other features.


First you will need to find out what your controller's Bluetooth address is.
1. Plug in your ESP32 and flash it with the starter code
1. Open the serial monitor
1. You should see your controller address as a string of octets (something like `98:B6:E1:7C:C3:95`) in the serial monitor while trying to connect your controller (press and hold power button on controller until lights slowly and then rapidly move to put it in pairing mode):
<img src="{{ '/_assets/images/controller_address.png' | prepend: site.baseurl }}" alt="controller_address :(">

1. Try adding your controller's Bluetooth address through the serial terminal:
<img src="{{ '/_assets/images/add_bluetooth.png' | prepend: site.baseurl }}" alt="add_bluetooth.png :(">

1. Controller should be able to connect now, and the controller data should begin streaming in the serial monitor after connecting

## Accessing controller data

In the sample code, there is a handle (i.e. pointer) for your controller called `myCtl` defined at the top of the `loop()` function. You can use the `ControllerPtr` class's helper functions to read data from the controller into your code logic.

This means you will have to pass the controller handle into functions if you want to use them in there. TODO: do we want to just make the myCtl handle a global var

{: .highlight}
You **must** call `BP32.update()` to update the values being read into your ESP32, and **then** you call helper functions (i.e. `a()` or `x()`) to actually retrieve the controller values.
{: .callout-red}

To see how to access the different peripherals on your controller, check out the sample code's `dumpGamepad()` function! Alternatively, you can hover over a function defined by BluePad32 and `Ctrl + Left Click` to see the actual source code for it. Yet another alternative is to go dig around on the official BluePad32 docs.







