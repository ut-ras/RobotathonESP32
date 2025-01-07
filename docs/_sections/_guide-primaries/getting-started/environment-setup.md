---
layout: default
title: Environment Setup
nav_include: true
parent: Getting Started
nav_order: 5
---

# Environment Setup

The end goal of this setup is to flash your ESP32 with blink program which flashes the onboard LED. 

All of the software to be installed includes:
1) VS Code with ESP-IDF
1) Git
1) SiLabs USB-UART bridge driver

The exact process to arrive at this goal depends on what OS your computer is running (Windows, macOS, etc.)

For explanations on what each of these components are, take a look at the FAQ! TODO: WRITE THIS LOL

## Windows Setup

It is highly recommended to follow each component installation in order.

__Install Git__
1) Go to the Git website at [https://git-scm.com/downloads](https://git-scm.com/downloads)
1) Download the 64-bit installer
1) Run the newly downloaded installer and follow the defaults in the installer dialogue
1) Open Git bash and familiarize yourself with how to navigate the bash terminal [(How do I do that?)](todo: link)

__Create GitHub account__
Go to GitHub and create an account if you do not have one already [https://github.com/](https://github.com/)

__Fork RobotathonESP32 Repository__

{: .highlight}
Note: only one person in each team has to fork the repository and share it with their teammates. Everybody that wants to code (including the person that forks) has to clone the repo to their local computer storage!
{: .callout-blue}

1) Navigate to the RobotathonESP32 repository hosted on GitHub [https://github.com/ut-ras/RobotathonESP32](https://github.com/ut-ras/RobotathonESP32)
1) Click the Fork button on the right

1) Change the Repository name to whatever you like
1) Click “Create fork”
1) Share repository access to your teammates by navigating to the settings of your newly forked repository and clicking collaborators in the left menu


__Set Up Git SSH Authentication__
TODO optional but makes life for them easier bc no password needed to push code
Set this up in git bash
https://docs.github.com/en/enterprise-cloud@latest/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent


__Clone RobotathonESP32 Repository__
1) Go to the newly forked repository
1) Click the green “<> Code” button
1) Copy the HTTPS or SSH git link (What is the difference?)
1) Open Git bash and navigate to where you want to keep your code for the competition (i.e. Documents, Desktop, etc.)
1) Run the following command into your Git terminal (to paste into git terminal, you can either right click -> paste or use keybind shift + insert)
`git clone https://github.com/ut-ras/RobotathonESP32.git`



__Install USB-UART Bridge Driver__
This allows your computer to recognize and program your ESP32 when you plug it in.
1) Go to SiLabs installer webpage [https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads)

Download the following file:
TODO: add picture

1) Extract the downloaded zip file and run the appropriate installer application inside (likely x64)
1) Agree and use default configuration

_Install 7-zip_
This step is optional, but it will save you at least 30 minutes when unzipping your VSCode installation
1) Go to the 7-zip download page [https://www.7-zip.org/](https://www.7-zip.org/)
1) Install using default directory
TODO: How to use 7-zip



__Install VSCode with ESP-IDF__
Do this even if you already have VSCode on your computer since we to minimize all environment setup issues by controlling more variables. Installing the ESP-IDF extension manually may result in much unecessary debugging.

1) Download zip folder from Box https://utexas.box.com/s/tsut1wgfh9d5dv1woty68pz4q4cu2wsm 
1) Unzip the file to your C: drive (this WILL take a while unless you use 7-zip from last section)
1) Launch the "containerized" VSCode by running the Code.exe file in the unzipped folder
1) In the top menu bar of VSCode, click File > Open Folder
1) Open the folder where you cloned the Robotathon Git repository (should be “RobotathonESP32” by default)
1) Wait for ESP-IDF to initialize
1) Build the project by clicking the wrench icon in the bottom ribbon of VSCode (this will take a while)

__Flash your ESP32__
1) Plug in your ESP32
1) Click the “COM1” (plug icon) in VSCode’s bottom ribbon menu
1) In the popup dialogue at the top of VSCode, select the COM port labeled Silicon Labs

1) Click the Flash button (lightning button) in the bottom ribbon menu 
1) Select UART in the popup menu

1) Press and hold the flash enable button on your ESP32 (small black button labeled “100”) until the following output shows in your terminal:

1) Open the serial monitor (monitor/TV icon)

Note: Building and flashing after the first time does not take nearly as long. In fact, you can press the Build, Flash, and Monitor button (fire icon) to streamline the process








## Programming goal
For this tutorial, we will control the onboard microcontroller by toggling it on and off periodically. This will serve as the goal for the Blink Checkpoint and demonstrates that you can flash your own program to the ESP32. If you are having trouble configuring your development environment, reference the setup guide on our [Github (scroll down)](https://github.com/ut-ras/RobotathonESP32) or ask a mentor for help!

Once your environment is set up, you should be able to flash the program to your ESP32 by 
1. Copying it into the ```arduino_main.cpp``` file
1. Pressing the fire icon (build + flash) in VSCode's bottom ribbon 
1. Holding the BOOT button on the ESP32 (button to the right of the USB port that puts it into flashing mode) 
1. Waiting until the Serial Monitor shows up

The following program will blink the onboard LED (pin 2) on the ESP32 every second:

{: .highlight}
Note: While it is good coding practice to leave comments in your code to make it more understandable, they should be used sparingly to explain complex code — the below example has many comments for the sake of explanation.
{: .callout-blue}

```cpp
#include "sdkconfig.h"
#include <Arduino.h>

#define LED_BUILTIN 2 // defines the word "LED_BUILTIN" as the number 2 for ease of use/readability when using the pin later

void setup() {
    pinMode(LED_BUILTIN, OUTPUT); // configures pin 2 to be a GPIO output pin 
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH); // writes a digital high to pin 2
    delay(1000); // waits for 1000 milliseconds (1 second)
    digitalWrite(LED_BUILTIN, LOW); // writes a digital low to pin 2
    delay(1000);
}
```



