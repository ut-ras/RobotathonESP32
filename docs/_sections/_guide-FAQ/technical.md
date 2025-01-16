---
layout: default
title: Technical
nav_include: true
nav_order: 1
---

# Technical FAQ

## Why does my build fail?

## What is the difference between cloning using HTTPS and SSH?
HTTPS (Hypertext Transfer Protocol Secure) and SSH (Secure Shell) are both data transfer protocols used in networking

The main reason why you should use SSH over HTTPS is that you can push code to your repositories without having to input credentials each time (HTTPS requires credentials each push, which is annoying).
TODO elaborate more

## How do I navigate the bash terminal for Robotathon?

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

## I've tried to add my controller's Bluetooth address, but my controller still isn't connecting!
There is a maximum storage of 4 Bluetooth addresses in the allow-list. Simply remove an existing one and replace it with your controller’s Bluetooth address.
<img src="{{ '/_assets/images/allowlist_list.png' | prepend: site.baseurl }}" alt="allowlist_list :(">
<img src="{{ '/_assets/images/allowlist_remove.png' | prepend: site.baseurl }}" alt="allowlist_remove :(">
<img src="{{ '/_assets/images/allowlist_add.png' | prepend: site.baseurl }}" alt="allowlist_add :(">

If this fails, then try [hard resetting your ESP32’s flash memory](https://randomnerdtutorials.com/esp32-erase-flash-memory/)


## I tried doing the above, but my controller isn’t connecting! How do I troubleshoot?(See the [official docs](https://bluepad32.readthedocs.io/en/latest/FAQ/#:~:text=true)%3B%0A%7D-,Using%20allowlist%20commands%20from%20the%20USB%20console,%C2%B6,-Note)

This is probably an issue with BluePad32’s whitelisted connections. You will not be able to connect your controller to the ESP32 without adding your controller’s Bluetooth address to the whitelist.

Try manually adding your controller's Bluetooth address through the serial terminal

## I can’t flash my ESP32 because of a “fatal error”! What should I do?
<img src="{{ '/_assets/images/fatal_error.png' | prepend: site.baseurl }}" alt="fatal_error.png :(">

It sounds silly, but first check if your ESP32 is plugged in.

Otherwise, this is usually caused by one of the other terminals in VS Code occupying the serial port.

<img src="{{ '/_assets/images/trash_terminal.png' | prepend: site.baseurl }}" alt="trash_terminal.png :(">
Delete all the terminals by clicking the trash icon for all of them and then try clicking the flash button again.

If that fails, close VS Code and reopen it.

If *that* fails, then check if there are any other applications on your computer that are occupying the COM port (extreme solution is to restart computer).

## How to calibrate the QTR line sensor?

<!-- ## Why doesn’t anything show up when I try printing to the serial monitor? -->
<!-- idk if this is actually na issue?? -->