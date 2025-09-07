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
It is highly recommended to follow everything in order!
{: .callout-blue}

### __Install Git__
This is a source-control application that is very useful for sharing projects with many files.

1. Go to the [Git website](https://git-scm.com/downloads)
2. Download the 64-bit installer
3. Run the newly downloaded installer and follow the defaults in the installer dialogue
4. Open Git Bash and familiarize yourself with how to navigate the bash terminal [(How do I do that?)](https://ut-ras.github.io/RobotathonESP32/technical#what-is-a-bash-terminal)

### __Create GitHub account__
GitHub is a cloud service for saving your Git repositories online. Go to the [GitHub website](https://github.com/) and create an account if you do not have one already. 

### __Fork RobotathonESP32 Repository__
Forking a repository creates a copy that you control on your GitHub account. Teams will use our RobotathonESP32 repo as the template. 

{: .highlight}
Note: only **one** person in each team has to fork the repository and invite their teammates to it on Github. **Everybody** that wants to code __including the person that forks__ has to clone the repo to their local computer storage!
{: .callout-red}

1. Go to the [ut-ras RobotathonESP32 repository hosted on GitHub](https://github.com/ut-ras/RobotathonESP32)
2. Click the `Fork` button on the right
<img src="{{ '/_assets/images/fork1.png' | prepend: site.baseurl }}" alt="fork1.png :(">
3. Keep the repository name as `RobotathonESP32`
<img src="{{ '/_assets/images/fork2.png' | prepend: site.baseurl }}" alt="fork2.png :(">
4. Click the green `Create fork` button at the bottom
5. Share repository access to your teammates by navigating to the settings of your newly forked repository and clicking collaborators in the left menu [(How do 6 invite teammates to my forked repository?)](getting-started/git#how-do-i-invite-my-teammates-to-my-forked-repository-on-github)

### __Set Up Git SSH Authentication__
This allows for easy and secure interfacing with Git when you want to touch your repositories. The SSH keys are a nice way to authenticate your identity with GitHub.

See the [official GitHub tutorial](https://docs.github.com/en/enterprise-cloud@latest/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent) if you want more information. Otherwise just follow these instructions:

#### Generate SSH key

{: .highlight}
Git Bash is finicky and doesn't support Ctrl + V for paste. Use `Shift + Insert` or `Right Click > Paste` to paste text.
{: .callout-blue}

1. Open Git Bash
2. Paste `ssh-keygen -t ed25519 -C "your_email@example.com"`, change the email to the one tied to your Github account (keep the quotes), and press `Enter`.
3. You will be prompted to specify a location to save the SSH key. Press `Enter` to specify the default location.
4. You will likely be prompted to enter a passcode. Press `Enter` twice to specify no passcode.

{: .highlight}
You can add a passcode if you'd like, but it is not recommended. If you do, keep in mind that the Bash terminal does _not_ show your passcode as you type it out. Just continue (accurately) typing and press `Enter` when done.
{: .callout-blue}

#### Add SSH key to SSH-agent
1. Paste `eval "$(ssh-agent -s)"` into the terminal and press `Enter` to start the SSH-agent
2. Paste `ssh-add ~/.ssh/id_ed25519` into the terminal and press `Enter` to add your key to the SSH-agent

#### Add SSH key to Github
1. Paste `cat ~/.ssh/id_ed25519.pub` into the terminal and press `Enter` to display your public SSH key
2. Copy the entire key

{: .highlight}
The key should look something like `ssh-ed25519 SFNJNAFNEJKFNJNJKNFJHFJAHOHiowuroiuwr/sfjeher+KX/rH email@gmail.com`
{: .callout-blue}

1. Navigate to the upper-right corner of any page on [GitHub](https://github.com/), click your profile photo, then click Settings (gear icon)
<img src="{{ '/_assets/images/github_settings.png' | prepend: site.baseurl }}" alt="my_image.png :(">
2. In the `Access` section of the sidebar, click `SSH and GPG keys`
3. Click the green `New SSH key` button on the right
<img src="{{ '/_assets/images/github_ssh_gpg.png' | prepend: site.baseurl }}" alt="my_image.png :(">
4. Put whatever you want for the key title name
5. Select the key type to be `Authentication`
6. Paste in the key you copied earlier into the `Key` section
7. Click `Add SSH Key`

### __Clone Forked Repository__
Cloning is the process of copying a Git repository onto your local computer storage. Everyone has to do this to work on code!

1. Go to your team's newly forked repository
<img src="{{ '/_assets/images/github_repo.png' | prepend: site.baseurl }}" alt="my_image.png :(">
2. Click the green `<> Code` button
3. If you did the previous section, copy the SSH git link. Otherwise copy the HTTPS link. [What is the difference?](https://ut-ras.github.io/RobotathonESP32/technical#what-is-the-difference-between-cloning-using-https-and-ssh)
<img src="{{ '/_assets/images/ssh_link_copy.png' | prepend: site.baseurl }}" alt="my_image.png w=200 h=400 :(">
4. Open Git Bash and navigate to where you want to keep your code for the competition, such as your Documents or Desktop. [How do I do that?](https://ut-ras.github.io/RobotathonESP32/technical#how-do-i-navigate-the-git-bash-terminal)
5. Run the following command in your Git terminal: `git clone [PASTE GIT LINK HERE]` without the square brackets

### __Install USB-UART Bridge Driver__
This allows your computer to recognize and program your ESP32 when you plug it in.

1. Go to [SiLabs installer webpage](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads)
2. Download the file named `CP210x Windows Drivers`
3. Extract the downloaded zip file and run the appropriate installer application inside (likely x64)
4. Agree and use default configuration

### __Install 7-zip__
7-zip is a file compression tool that works much faster than your native Windows tools.

1. Go to the [7-zip download page](https://www.7-zip.org/)
2. Install using defaults
3. Launch 7-zip

### __Install Preconfigured VS Code__
VS Code is an easily customizable IDE with many extensions and a large community. The preconfigured version you will download will already have the ESP-IDF extension installed for convenience.

{: .highlight}
Do this even if you already have VS Code to minimize environment setup issues. Installing the ESP-IDF extension normally may result in unecessary debugging.
{: .callout-red}    

1. Download [zip folder from Box](https://utexas.box.com/s/2enfprqovfq8kmgcz8d8sn28yr6wpzt4) 
2. Unzip the file to your C: drive 
{: .highlight}
This **will** take a while unless you use 7-zip. [How do I use 7-zip?](https://ut-ras.github.io/RobotathonESP32/technical#how-do-i-use-7-zip)
{: .callout-blue}

3. Launch the "containerized" VS Code by running the `Code.exe` file in the unzipped folder
4. In the top menu bar of VS Code, click `File` > `Open Folder`
5. Use VS Code to open the folder where you cloned the Robotathon repository (“RobotathonESP32” by default)
6. Wait for the ESP-IDF extension to initialize 
7. Build the project by clicking the wrench icon in the bottom ribbon of VS Code (this will take a while the first time)
<img src="{{ '/_assets/images/vscode_bottom_ribbon_build.png' | prepend: site.baseurl }}" alt="vscode_bottom_ribbon_build.png :(">

### __Flash your ESP32__

1. Plug in your ESP32
2. Click the `COM` button (plug icon) in VS Code’s bottom ribbon menu
<img src="{{ '/_assets/images/vscode_bottom_ribbon_com.png' | prepend: site.baseurl }}" alt="vscode_bottom_ribbon_com.png :(">

3. In the popup dialogue at the top of VS Code, select the COM port labeled `Silicon Labs`
<img src="{{ '/_assets/images/COM_port.png' | prepend: site.baseurl }}" alt="COM_port.png :(">

4. Click the Flash button (lightning button) in the bottom ribbon menu
<img src="{{ '/_assets/images/vscode_bottom_ribbon_flash.png' | prepend: site.baseurl }}" alt="vscode_bottom_ribbon_flash.png :(">

5. Select UART in the top popup menu 
<img src="{{ '/_assets/images/UART_selection.png' | prepend: site.baseurl }}" alt="UART_selection.png :(">

6. Press and hold the flash enable button on your ESP32 (small black button labeled “100”) until the following output shows in your terminal:

7. Open the serial monitor (monitor/TV icon)
<img src="{{ '/_assets/images/vscode_bottom_ribbon_monitor.png' | prepend: site.baseurl }}" alt="my_image.png :(">

{: .highlight}
Building and flashing after the first time does not take nearly as long. In fact, you can press the Build, Flash, and Monitor button (fire icon) to streamline the process!
{: .callout-blue}


# Example Program

Here is an example program that blinks the onboard LED. "Blinky" projects are a standard "hello world" type of program that demonstrate your development environment works properly.

If you replace your `arduino_main.cpp` file's contents with the following, build, and flash properly, then your ESP32's blue onboard LED will begin to blink every second (yay 😄)!

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


{: .highlight}
Tip: Make sure to enable auto-save in your VS Code! It will save you a lot of headaches down the road :)
{: .callout-blue}

