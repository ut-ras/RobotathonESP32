---
layout: default
title: Technical
nav_include: true
nav_order: 1
---

# Technical FAQ

## Why does my build fail?
Ensure their portable vscode installation is located in a path without spaces
Document instance where they have spaces in name
- Solution is to move project directory to C drive
TODO: Document reading the error messages (i.e. starting from the first error culprit fixes ones below etc etc)

## What is the difference between cloning using HTTPS and SSH?
HTTPS (Hypertext Transfer Protocol Secure) and SSH (Secure Shell) are both data transfer protocols used in networking

The main reason why you should use SSH over HTTPS is that you can push code to your repositories without having to input credentials each time (HTTPS requires credentials each push, which is annoying).
TODO elaborate more

## I've tried to add my controller's Bluetooth address, but my controller still isn't connecting!
There is a maximum storage of 4 Bluetooth addresses in the allow-list. Simply remove an existing one and replace it with your controller’s Bluetooth address.
<img src="{{ '/_assets/images/allowlist_list.png' | prepend: site.baseurl }}" alt="allowlist_list :(">
<img src="{{ '/_assets/images/allowlist_remove.png' | prepend: site.baseurl }}" alt="allowlist_remove :(">
<img src="{{ '/_assets/images/allowlist_add.png' | prepend: site.baseurl }}" alt="allowlist_add :(">

If this fails, then try [hard resetting your ESP32’s flash memory](https://randomnerdtutorials.com/esp32-erase-flash-memory/) and try again!



## Why bother with the whitelisted Bluetooth connections for the controller?
Connecting the controller without a specific address when many robots are powered on in close proximity is a nightmare.

## I can’t flash my ESP32 because of a “fatal error”! What should I do?
<img src="{{ '/_assets/images/fatal_error.png' | prepend: site.baseurl }}" alt="fatal_error.png :(">

It sounds silly, but first check if your ESP32 is plugged in.

Otherwise, this is usually caused by one of the other terminals in VS Code occupying the serial port.

<img src="{{ '/_assets/images/trash_terminal.png' | prepend: site.baseurl }}" alt="trash_terminal.png :(">
Delete all the terminals by clicking the trash icon for all of them and then try clicking the flash button again.

If that fails, close VS Code and reopen it.

If *that* fails, then check if there are any other applications on your computer that are occupying the COM port (extreme solution is to restart computer).

## How does the ESP-IDF build system work?
This information is not required for the competition, but it can be good to know if you'd like to continue IoT develpoment with Espressif MCU's.

Here is a link to their official documentation: [https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html#component-requirements](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html#component-requirements)

## What is ESP-IDF?
ESP-IDF (**Esp**ressif **I**oT **D**evelopment **F**ramework) is the official development framework for Espressif's ESP32 microcontroller series.

For Robotathon, you will use the VS Code ESP-IDF extension to develop your robot's software.


## What is a Bash terminal?

Before **graphic user interfaces** (GUI) were common in computers way back in the day, users had to rely on **command-line interfaces** (CLI) or terminals to interface with the computer. As you may have guessed, CLI's and Bash are probably way older than you are (Bash was released in 1989!), so there is much history if you'd like to learn more [(Wikipedia article)](https://en.wikipedia.org/wiki/Bash_(Unix_shell)).

A **Bash terminal** is a CLI where you type in various commands to execute tasks like file management, application execution, and scripting (literally anything) through Bash terminals. 

It is the standard CLI for Unix (Linux/macOS) systems today, and is powerful even on Windows machines as seen with Windows Subsystem for Linux (WSL).

For Robotathon, you will be using a Bash terminal emulator called **Git Bash**, which will allow you to use Bash commands on your Windows machine.

The main use for Git Bash in Robotathon will be for Git and file management. While you could get away with your OS's native file explorer GUI, you can do everything and more with the Bash terminal!

Some of the most important commands include:
* ls (list files)
* cd (change directory)
* git (invokes various git functionalities)
* mkdir (create directory)
* rm (remove files)
* cp (copy files)
* mv (move or rename files)
* cat (display file contents)
* grep (search for patterns in files)


{: .highlight}
Note that you probably will only need to use the first three commands to complete Robotathon, but it's good to learn the others
{: .callout-blue}

Commands will often come with extra functionalities that you can invoke through the use of **options/flags**.

For example, `rm` by default can only delete single files, while `rm -rf` can delete entire folders that have files in them.

Another example is `git commit -m`, where the `-m` flag tells Git that you want to specify an inline message instead of opening the terminal text editor.

If you want to know how to actually use these commands, it would be a good exercise to Google them (as you should whenever you get stuck) and try them out on your own! 

## How do I navigate the Git Bash terminal?
You will primarily use the `ls` and `cd` commands to navigate to your Git repository.

By default, Git Bash starts up in your user's home folder in Windows as denoted by the tilde `~`. This **path** will change as you move through directories using `cd`.

Here is a little exercise to navigate to a sample directory in desktop and create a folder:

1. Navigate to your Desktop directory (a.k.a. folder) in Git Bash by using a combination of `ls` and `cd`. 
1. Type `mkdir [directory name]`

* The pictures below demonstrate navigating to an existing `sample` directory on the `Desktop` directory
    * Typing `cd Desktop/sample` would have achieved the same result as `cd Desktop` `cd sample`
<img src="{{ '/_assets/images/before_sample_dir.png' | prepend: site.baseurl }}" alt="before_sample_dir :(">
<img src="{{ '/_assets/images/bash_term.png' | prepend: site.baseurl }}" alt="bash_term :(">
<img src="{{ '/_assets/images/sample_dir.png' | prepend: site.baseurl }}" alt="sample_dir :(">

1. Navigate back a directory by typing `cd ..`
1. Remove the newly created (empty) folder by typing `rmdir [directory name]`
<img src="{{ '/_assets/images/rmdir.png' | prepend: site.baseurl }}" alt="rmdir :(">

In a similar fashion, Git commands require you to navigate to your Git repository's directory!


## What is the SiLabs USB-UART driver for?
The SiLabs USB-UART driver is an application that allows your computer to send and receive serial data through a standard USB port by treating the device as a virtual COM port. This is commonly used to connect devices like microcontrollers or other serial-based devices to a computer via USB. 

It translates USB data into serial data (UART) and vice versa, allowing applications to interact with a connected device (your microcontroller) as if it were a traditional serial port. 


## What is 7-zip?   
7-zip is an open source application used for file compression. It is a lot faster than the native Windows file extractor (50 minutes -> 1 minute).

## How do I use 7-zip?
To extract your zipped VS Code archive, follow these steps:
1. Locate and click the zipped archive you'd like to extract in the 7-zip file browser

<img src="{{ '/_assets/images/extract_7zip.png' | prepend: site.baseurl}}" alt="locate_file_7zip :(" width=300 height=200>
1. Click the `Extract` button at the top of the 7-zip GUI

<img src="{{ '/_assets/images/locate_file_7zip.png' | prepend: site.baseurl }}" alt="extract_7ip :(" width=300 height=200>
1. Set the `Extract to` path to `C:` 

<img src="{{ '/_assets/images/extract_target_7zip.png' | prepend: site.baseurl }}" alt="path_7zip :(" width=300 height=200>
1. Click `OK` and wait for the unzipping to finish
