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


## I tried doing the above, but my controller isn’t connecting! How do I troubleshoot?
See [BluePad32's official docs](https://bluepad32.readthedocs.io/en/latest/FAQ/#:~:text=true%3B%0A%7D-,Using%20allowlist%20commands%20from%20the%20USB%20console,%C2%B6,-Note)

This is probably an issue with BluePad32’s whitelisted connections. You will not be able to connect your controller to the ESP32 without adding your controller’s Bluetooth address to the whitelist.

Try manually adding your controller's Bluetooth address through the serial terminal

If this fails, then try [hard resetting your ESP32’s flash memory](https://randomnerdtutorials.com/esp32-erase-flash-memory/)

## Why bother with the whitelisted Bluetooth connections for the controller?
In previous years, connecting the controller when many robots were powered on in close proximity was a nightmare because connecting to the wrong robot was unfortunately inevitable.

## I can’t flash my ESP32 because of a “fatal error”! What should I do?
<img src="{{ '/_assets/images/fatal_error.png' | prepend: site.baseurl }}" alt="fatal_error.png :(">

It sounds silly, but first check if your ESP32 is plugged in.

Otherwise, this is usually caused by one of the other terminals in VS Code occupying the serial port.

<img src="{{ '/_assets/images/trash_terminal.png' | prepend: site.baseurl }}" alt="trash_terminal.png :(">
Delete all the terminals by clicking the trash icon for all of them and then try clicking the flash button again.

If that fails, close VS Code and reopen it.

If *that* fails, then check if there are any other applications on your computer that are occupying the COM port (extreme solution is to restart computer).

## How to calibrate the QTR line sensor?
TODO actualy make sure u incorporate this in the main guide portion lol

## How does the ESP-IDF build system work?
This information is not required for the competition, but it can be good to know if you'd like to continue IoT develpoment with Espressif MCU's.

Here is a link to their official documentation: [https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html#component-requirements](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html#component-requirements)

## What is ESP-IDF?
ESP-IDF (**Esp**ressif **I**oT **D**evelopment **F**ramework) is the official development framework for building applications for Espressif's ESP32 microcontroller series.

For Robotathon, you will use the VS Code ESP-IDF extension to develop your robot's software.

## How do I navigate the Git Bash terminal?
You will primarily use the `ls` and `cd` commands to navigate to your Git repository.

By default, Git Bash starts up in your user's folder in Windows as denoted by the tilde `~`. This **path** will change as you move through directories using `cd`.

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

## What is a Bash terminal?
The Bash terminal is a **command-line interface** (CLI) where you type in various commands to execute tasks. The main use for Git Bash in Robotathon will be for Git and file management. While you could get away with your OS's native file explorer GUI, you can do everything and more with the Bash terminal!

Some of the most important commands include:
* ls (list files)
* cd (change directory)
* mkdir (create directory)
* rm (remove files)
* cp (copy files)
* mv (move or rename files)
* cat (display file contents)
* grep (search for patterns in files)

You can use various `options/flags` to change the functionality of commands.

For example, `rm` by default can only delete single files, while `rm -rf` can delete entire folders.



## What is the SiLabs USB-UART driver for?
