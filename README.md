RobotathonESP32
====================

This is the repository that utilizes the ESP32 to control robots for the Robtathon competition. It uses the following components:
* [ESP-IDF Extension for VSCode](https://github.com/espressif/vscode-esp-idf-extension)
* [Bluepad32](https://github.com/ricardoquesada/bluepad32/tree/main)

Getting Started
===================

## 1. VSCode
This project was built and tested using VSCode. Although any IDE should work in theory, you will not get the features provided by the ESP-IDF extension and will likely need to work through the command line. As such, using VSCode is highly recommended.

VSCode can be installed [from here](https://code.visualstudio.com/).

## 2. Using this Template
This repo is a template repository, meaning you can use it in your own team's repository.  

To use this template, go to the main page of our repo and press ```Use this Template``` and then ```Create a new repository```.  Enter in the repository name and press ```Create Repository```.

Once your repository is created add your teammates by going to ```Settings```->```Collaborators```->```Manage Access``` then put in their GitHub usernames.

## 3. Cloning the Repo
Clone this repo to a location using the method of your choice. I prefer to use the command line, although any method will do. If you do not have a terminal environment set up then I recommend [Git Bash](https://git-scm.com/downloads). On GitHub go to the green button that says ```Code``` and copy the link. Paste the command below in your Git Bash to the location you would like the project to be.
```sh
git clone [link you copied]
```

## 4. WSL Setup (Windows only)
*Only necessary if you are on Windows. If you are using either Linux or MacOS, proceed to step 5.*

To streamline development between different platforms, there exists a ESP-IDF Docker image that ensures everyone has the same development environment. Due to issues with Docker USB passthrough on Windows, we will be utilizing Windows Subsystem for Linux (WSL) as a workaround.

To install WSL, open a Command Prompt in Administrator Mode and enter the following command:
```cmd
wsl --install
```

By default, this should install Ubuntu. This project setup has only been tested on Ubuntu, although you may choose to install a different distribution of Linux if you wish with:
```cmd
wsl --install -d <Distribution Name>
```

After installation, you can open the distribution from the Start terminal by looking for "Ubuntu". The first time you run Ubuntu on WSL, you will be prompted to create a username and password. Please see [this guide](https://learn.microsoft.com/en-us/windows/wsl/setup/environment) for more details.


## 5. Running Docker Container
By default, Ubuntu should come with Docker Engine already installed. If it is missing (or if you are running a different distribution or OS), you can install docker following [these instructions](https://docs.docker.com/get-docker/).

To run the container, use the following command in your terminal:
```sh
docker run --rm -v $PWD:/project -w /project -u $UID -e HOME=/tmp -it espressif/idf
```

Once the container is built and running, you can use `idf.py` as usual. For example, you can try building this project with the following command:
```sh
idf.py build
```
# Deprecated, need to update
## 6. Install the ESP-IDF Extension
The [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) is a developement framework that is used to build and flash for the ESP32. While it can be [installed manually](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows-setup.html), we highly recommend that you install it using the VSCode extension.

To install the ESP-IDF Extension, simply go click on the Extension icon in the right taskbar in VSCode and search for "Espressif IDF". Click install.

Full installation and setup instructions be [found here](https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/install.md).

## 7. Build and Flash
To build for the ESP32, click the "Build Project" button (cylinder) in the bottom taskbar.

To flash onto an ESP32, click the "Flash Project" button (lightning bolt) in the bottom taskbar.

To read serial output coming from the ESP32, click the "Monitor Device" button (monitor) in the bottom taskbar.
