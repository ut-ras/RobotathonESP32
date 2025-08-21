---
layout: default
title: Bluetooth Controller
nav_include: true
parent: Getting Started
nav_order: 6
---

# Bluetooth Controller

You will be connecting a wireless game controller to your ESP32 for controlling your robot (i.e. triggering autonomous modes, moving between challenges, and triggering your launch mechanism)

That being said, you will not earn points for manually driving your robot through the challenges, as that defeats the purpose of having the sensors.

It is highly recommended that you map autonomous sensors modes (line, color, distance) to specific buttons on the remote controller so that you have more control over your robot's behavior (i.e. press A -> autonomous color mode, press B -> exit to normal drive mode).

See [BluePad32's official docs](https://bluepad32.readthedocs.io/en/latest/FAQ/#:~:text=true%3B%0A%7D-,Using%20allowlist%20commands%20from%20the%20USB%20console,%C2%B6,-Note) if you'd like to see other features.


The process for interfacing your controller to the ESP32 is as follows:
1. Find controller Bluetooth address
1. Add address to ESP32 allowlist
1. Connect controller & stream data!

## Finding Bluetooth Address

{: .highlight}
Note that your controller will likely have the address already labeled on it on the back for ease of use, so you can easily jump to the next section
{: .callout-blue}

1. Plug in your ESP32 and flash it with the Robotathon starter code your team should have forked 
1. Open the serial monitor
<img src="{{ '/_assets/gifs/controller_listen.gif' | prepend: site.baseurl }}" alt="controller_listen.gif">
*Opening the serial monitor through the ESP-IDF extension GUI*
1. You should see your controller address as a string of octets (something like `98:B6:E1:7C:C3:95`) in the serial monitor while trying to connect your controller (press and hold power button on controller until lights slowly and then rapidly move to put it in pairing mode)
<img src="{{ '/_assets/gifs/controller_not_allowed.gif' | prepend: site.baseurl }}" alt="controller_not_allowed.gif">
*Viewing your controller's Bluetooth address*
* Look for something like this when finding your controller's address:
<img src="{{ '/_assets/images/controller_address.png' | prepend: site.baseurl }}" alt="controller_address :(">

## Adding Bluetooth Address
* Try adding your controller's Bluetooth address through the serial terminal:
    * `allowlist_add <BLUETOOTH ADDY>`
* Now check that the ESP32 actually accepted the address:
    * `allowlist_list`

<img src="{{ '/_assets/images/add_bluetooth.png' | prepend: site.baseurl }}" alt="add_bluetooth.png :(">
*Adding and checking Bluetooth address*

## Accessing controller data
* The controller should be able to connect now, and the data should begin streaming in the serial monitor after connecting

<img src="{{ '/_assets/gifs/controller_dump.gif' | prepend: site.baseurl }}" alt="controller_dump.gif">
*Streaming controller data from ESP32*


## Code

In the sample code, there is a handle (i.e. pointer) for your controller called `myController` defined at the top of the `loop()` function. You can use the `ControllerPtr` class's helper functions to read data from the controller into your code logic.

This means you will have to pass the controller handle into functions if you want to use them in there. Here is a basic example:

{: .highlight}
This sample only provides the basic structure of how you would break your logic up into different functions. You may edit it however you please!
{: .callout-blue}

```
#include "sdkconfig.h"
#include <Arduino.h>
#include <Bluepad32.h>
#include <uni.h>
#include "controller_callbacks.h"

extern ControllerPtr myControllers[BP32_MAX_GAMEPADS]; // BP32 library allows for up to 4 concurrent controller connections, but we only need 1

void foo(ControllerPtr myController) {
    BP32.update();
    while(1) {
        if(myController->a()) {
            Console.printf("hi");
            return;
        }
    }
}

void setup() {
    BP32.setup(&onConnectedController, &onDisconnectedController);
    BP32.forgetBluetoothKeys(); 
    esp_log_level_set("gpio", ESP_LOG_ERROR); // Suppress info log spam from gpio_isr_service
    uni_bt_allowlist_set_enabled(true);
}

void loop() {

    vTaskDelay(1); // Ensures WDT does not get triggered when no controller is connected
    BP32.update(); 

    for (auto myController : myControllers) { // Only execute code when controller is connected
        if (myController && myController->isConnected() && myController->hasData()) {        
            
            foo(myController);

        }
    }
}
```

TODO: check if we can simplify the above code by removing the for loop
just hardcode the `myController` pointer to always be myControllers[0]?

TODO: check if the code actually builds lmao

{: .highlight}
You **must** call `BP32.update()` to update the current controller values, and then call helper functions (i.e. `myController->a()` or `myController->x()`) to actually retrieve the controller values.
{: .callout-red}

To see how to access the different peripherals on your controller, check out the sample code's `dumpGamepad()` function! Alternatively, you can hover over a function defined by BluePad32 and `Ctrl + Left Click` to see the actual source code for it (if your VS Code isn't being dumb). Yet another alternative is to go dig around on the official [BluePad32 docs](https://bluepad32.readthedocs.io/en/latest/FAQ/#:~:text=true%3B%0A%7D-,Using%20allowlist%20commands%20from%20the%20USB%20console,%C2%B6,-Note).







