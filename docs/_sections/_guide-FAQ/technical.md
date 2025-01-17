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


## I tried doing the above, but my controller isn’t connecting! How do I troubleshoot?
See [BluePad32's official docs](https://bluepad32.readthedocs.io/en/latest/FAQ/#:~:text=true%3B%0A%7D-,Using%20allowlist%20commands%20from%20the%20USB%20console,%C2%B6,-Note)

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
TODO write this or link somewhere

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

## What is Git?
**Git** is a tool used for source/version control, which is the process of tracking changes to files over time.

It allows you to:

* Easily share code or other files with teammates
* Keep a history of your project
* Revert to previous versions if needed
* Work on new ideas or features without affecting the main project

A **repository** (or repo) is where all your files and their history are stored. Repositories can be stored locally on your computer or in a cloud service like GitHub or GitLab.

Git is especially helpful for teams because it tracks who made what changes and makes it easier to collaborate without overwriting each other’s work. This ability is indispensable for developing larger projects, especially in industry.

Note that Robotathon aims to give you a *basic* understanding of how Git/GitHub works. The whole picture is a lot more complicated and can take a bit of effort to learn!

## How do I make changes to my repository on GitHub?

1. Make changes to your local files
1. Navigate to your repo's root directory in Git Bash
1. Check your repo's status to see what will be added
1. Run `git add .` to stage your changes [What is staging?](TODO write this)
1. Run `git commit -m "message here"` to **commit** your change to your *local* repository
1. Run `git push` to write your changes to the *remote* repository on GitHub

TODO add picture

## What is staging in Git?
Instead of having to push every little change to your repository, you can group them into a collection of changes called a **commit**, which serve as a snapshot of the project's state.

The **staging area** in Git is where you can manage your changes before saving them to your commit.

For example, if you accidentally stage a file or change that you don't want in your commit (i.e. a build directory), you can simply remove it from the staging area by running `git restore --staged <file>`.

Once you verify that everything you want to commit is shown in `git status`, you can proceed to **commit** to your local  repository and then **push** your local repository to GitHub.

## What is a Git branch?
In Git, a **branch** is essentially a separate line of development within your project. Think of it like a parallel path you can take to work on something without affecting the main line of development.

You can then make changes and commit them to this branch without affecting the original branch (can be any).

Once you're finished working on a branch (i.e. a new feature, bug fix), you can **merge** it back into the original branch by starting a **pull request** on GitHub [How do I do that?](TODO write this)

Oftentimes this original branch is your `main` or `master` branch (though `main` is the recommended and default GitHub name), which is your project's stable version.

## What is a Git clone?

`git clone` is a command that creates a copy or _clone_ of a repository from a hosting service (i.e. GitHub, GitLab) to your computer's local storage.

When you clone a repository, you’re downloading all the files, the commit history, and the current state of the project so that you can work on it locally. It’s like taking a snapshot of a project from the remote server (like GitHub) and bringing it into your workspace.

{: .highlight}
Note that a cloned repository does **not** automatically update to reflect newly pushed commits to GitHub! To update and merge any changes, simply run `git pull` in your repostiory's root directory (i.e. `RobotathonESP32`)
{: .callout-blue}


## What is a Git fork?
A repo fork is like making your own personal copy of someone else’s project. When you fork a repository, you’re creating a separate version of it in your GitHub account so that you can make changes without affecting the original project.

You might fork a repo to experiment, add new features, fix bugs, or contribute to an open-source project. It lets you work independently of the original repo while still having access to its code and history.

## What is the difference between a Git repo fork and clone?
Forks are copies of a repo on GitHub (remote), while clones are repos stored on your computer (local).

## What is the SiLabs USB-UART driver for?
