---
layout: default
title: Windows Setup
nav_include: true
parent: Environment Setup
grand_parent: Getting Started
nav_order: 1
---

# Windows Setup

{: .highlight}
It is highly recommended to follow each component installation in order!
{: .callout-blue}

### __Install Git__
This is a source-control application that is very useful for sharing projects with many files.

1. Go to the [Git website](https://git-scm.com/downloads)
1. Download the 64-bit installer
1. Run the newly downloaded installer and follow the defaults in the installer dialogue
1. Open Git Bash and familiarize yourself with how to navigate the bash terminal [(How do I do that?)](https://ut-ras.github.io/RobotathonESP32/technical#what-is-a-bash-terminal)

### __Create GitHub account__
GitHub is like a Google Drive for your Git repositories.
Go to the [GitHub website](https://github.com/) and create an account if you do not have one already. 

### __Fork RobotathonESP32 Repository__
Forking a repository creates a copy that you control on your GitHub account. Teams will use our RobotathonESP32 repo as the template. 

{: .highlight}
Note: only **one** person in each team has to fork the repository and invite their teammates to it on Github. **Everybody** that wants to code __including the person that forks__ has to clone the repo to their local computer storage!
{: .callout-red}

1. Go to the [ut-ras RobotathonESP32 repository hosted on GitHub](https://github.com/ut-ras/RobotathonESP32)
1. Click the `Fork` button on the right and then click `+ Create a new fork` 
<img src="{{ '/_assets/images/github_fork.png' | prepend: site.baseurl }}" alt="my_image.png :(">
1. Change the Repository name to whatever you like
1. Click the green `Create fork` button at the bottom
1. Share repository access to your teammates by navigating to the settings of your newly forked repository and clicking collaborators in the left menu [(How do I invite teammates to my forked repository?)](https://ut-ras.github.io/RobotathonESP32/getting-started/git#how-do-i-invite-teammates-to-my-forked-repository)

### __Set Up Git SSH Authentication__

{: .highlight}
This SSH section is **optional**, but it will make your life easier down the road by letting you push code to your remote repository without manually typing credentials
{: .callout-blue}

See the [official GitHub tutorial](https://docs.github.com/en/enterprise-cloud@latest/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent) if you want more information. Otherwise just follow these instructions:

#### Generate SSH key

{: .highlight}
Git Bash is finicky and doesn't support Ctrl + V for paste. Use `Shift + Insert` or `Right Click > Paste` to paste text.
{: .callout-blue}

1. Open Git Bash
1. Paste `ssh-keygen -t ed25519 -C "your_email@example.com"`, change the email to the one tied to your Github account (keep the quotes), and press `Enter`.
1. You will be prompted to specify a location to save the SSH key. Press `Enter` to specify the default location.
1. You will likely be prompted to enter a passcode. Press `Enter` twice to specify no passcode.

{: .highlight}
You can add a passcode if you'd like, but it is not recommended. If you do, keep in mind that the Bash terminal does _not_ show your passcode as you type it out. Just continue (accurately) typing and press `Enter` when done.
{: .callout-blue}

#### Add SSH key to SSH-agent
1. Paste `eval "$(ssh-agent -s)"` into the terminal and press `Enter` to start the SSH-agent
1. Paste `ssh-add ~/.ssh/id_ed25519` into the terminal and press `Enter` to add your key to the SSH-agent

#### Add SSH key to Github
1. Paste `cat ~/.ssh/id_ed25519.pub` into the terminal and press `Enter` to display your public SSH key
1. Copy the entire key

{: .highlight}
The key should look something like `ssh-ed25519 SFNJNAFNEJKFNJNJKNFJHFJAHOHiowuroiuwr/sfjeher+KX/rH email@gmail.com`
{: .callout-blue}

1. Navigate to the upper-right corner of any page on [GitHub](https://github.com/), click your profile photo, then click Settings (gear icon)
<img src="{{ '/_assets/images/github_settings.png' | prepend: site.baseurl }}" alt="my_image.png :(">
1. In the `Access` section of the sidebar, click `SSH and GPG keys`
1. Click the green `New SSH key` button on the right
<img src="{{ '/_assets/images/github_ssh_gpg.png' | prepend: site.baseurl }}" alt="my_image.png :(">
1. Put whatever you want for the key title name
1. Select the key type to be `Authentication`
1. Paste in the key you copied earlier into the `Key` section
1. Click `Add SSH Key`

### __Clone Forked Repository__
Cloning is the process of copying a Git repository onto your local computer storage


1. Go to your team's newly forked repository
<img src="{{ '/_assets/images/github_repo.png' | prepend: site.baseurl }}" alt="my_image.png :(">
1. Click the green `<> Code` button
1. If you did the previous section, copy the SSH git link. Otherwise copy the HTTPS link. [What is the difference?](https://ut-ras.github.io/RobotathonESP32/technical#what-is-the-difference-between-cloning-using-https-and-ssh)
<img src="{{ '/_assets/images/ssh_link_copy.png' | prepend: site.baseurl }}" alt="my_image.png w=200 h=400 :(">
1. Open Git Bash and navigate to where you want to keep your code for the competition, such as your Documents or Desktop. [How do I do that?](https://ut-ras.github.io/RobotathonESP32/technical#how-do-i-navigate-the-git-bash-terminal)
1. Run the following command in your Git terminal: `git clone [PASTE GIT LINK HERE]` without the square brackets

### __Install USB-UART Bridge Driver__
This allows your computer to recognize and program your ESP32 when you plug it in.

1. Go to [SiLabs installer webpage](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads)
1. Download the file named `CP210x Windows Drivers`
1. Extract the downloaded zip file and run the appropriate installer application inside (likely x64)
1. Agree and use default configuration

### __Install 7-zip__

{: .highlight}
This step is **optional**, but it will save you at least 30 minutes when unzipping your VS Code installation.
{: .callout-blue}

7-zip is a file compression tool that works much faster than your native Windows tools.

1. Go to the [7-zip download page](https://www.7-zip.org/)
1. Install using defaults
1. Launch 7-zip

### __Install Preconfigured VS Code__
VS Code is an easily customizable IDE with many extensions and a large community. The preconfigured version you will download will already have ESP-IDF installed.

{: .highlight}
Do this even if you already have VS Code to minimize environment setup issues. Installing the ESP-IDF extension normally may result in unecessary debugging.
{: .callout-red}

1. Download [zip folder from Box](https://utexas.box.com/s/2enfprqovfq8kmgcz8d8sn28yr6wpzt4) 
1. Unzip the file to your C: drive 
{: .highlight}
This **will** take a while unless you use 7-zip. [How do I use 7-zip?](https://ut-ras.github.io/RobotathonESP32/technical#how-do-i-use-7-zip)
{: .callout-blue}
1. Launch the "containerized" VS Code by running the Code.exe file in the unzipped folder
1. In the top menu bar of VS Code, click `File` > `Open Folder`
1. Use VS Code to open the folder where you cloned the Robotathon repository (“RobotathonESP32” by default)
1. Wait for the ESP-IDF extension to initialize 
1. Build the project by clicking the wrench icon in the bottom ribbon of VS Code (this will take a while)
<img src="{{ '/_assets/images/vscode_bottom_ribbon_build.png' | prepend: site.baseurl }}" alt="vscode_bottom_ribbon_build.png :(">

### __Flash your ESP32__

1. Plug in your ESP32
1. Click the `COM` button (plug icon) in VS Code’s bottom ribbon menu
<img src="{{ '/_assets/images/vscode_bottom_ribbon_com.png' | prepend: site.baseurl }}" alt="vscode_bottom_ribbon_com.png :(">

1. In the popup dialogue at the top of VS Code, select the COM port labeled `Silicon Labs`
<img src="{{ '/_assets/images/COM_port.png' | prepend: site.baseurl }}" alt="COM_port.png :(">

1. Click the Flash button (lightning button) in the bottom ribbon menu
<img src="{{ '/_assets/images/vscode_bottom_ribbon_flash.png' | prepend: site.baseurl }}" alt="vscode_bottom_ribbon_flash.png :(">

1. Select UART in the top popup menu 
<img src="{{ '/_assets/images/UART_selection.png' | prepend: site.baseurl }}" alt="UART_selection.png :(">

1. Press and hold the flash enable button on your ESP32 (small black button labeled “100”) until the following output shows in your terminal:

1. Open the serial monitor (monitor/TV icon)
<img src="{{ '/_assets/images/vscode_bottom_ribbon_monitor.png' | prepend: site.baseurl }}" alt="my_image.png :(">

{: .highlight}
Building and flashing after the first time does not take nearly as long. In fact, you can press the Build, Flash, and Monitor button (fire icon) to streamline the process!
{: .callout-blue}


# Example Program

Here is an example program that blinks the onboard LED. "Blinky" projects are a standard "hello world" type of program that demonstrate your development environment works properly.

If you replace your `arduino_main.cpp` file's contents with the following and flash properly, then your ESP32's blue onboard LED will begin to blink (yay 😄)!

{: .highlight}
Note that it is **your** responsibility to integrate this code with the controller starter code!
{: .callout-blue}

```cpp
#include "sdkconfig.h"
#include <Arduino.h>

#define ONBOARD_LED_PIN 2 // defines the word "LED_BUILTIN" as the number 2 for readability

void setup() {
    pinMode(ONBOARD_LED_PIN, OUTPUT); // configures pin 2 to be a GPIO output pin 
}

void loop() {
    digitalWrite(ONBOARD_LED_PIN, HIGH); // writes a digital high to pin 2
    delay(1000); // waits for 1000 milliseconds (1 second)
    digitalWrite(ONBOARD_LED_PIN, LOW); // writes a digital low to pin 2
    delay(1000);
}
```



