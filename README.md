RobotathonESP32
====================

This is the repository that utilizes the ESP32 to control robots for the Robtathon competition. It uses the following components:
* [Arduino Core for ESP32](https://github.com/espressif/arduino-esp32)
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

Once your repository is created add your teammates by going to ```Settings```->```Collaborators```->```Manage Access``` then put in their github usernames.
## 3. Forking the Repo
Clone this repo to a location using the method of your choice. I prefer to use the command line, although any method will do. If you do not have a terminal environment set up then I recommend [Git Bash](https://git-scm.com/downloads) In your GitHub go to the green button that says ```Code``` and copy the link. Paste the command below in your Git Bash.
```sh
git clone [link you copied]
```
## 4. Install the ESP-IDF Extension
The [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) is a developement framework that is used to build and flash for the ESP32. While it can be [installed manually](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows-setup.html), we highly recommend that you install it using the VSCode extension.

To install the ESP-IDF Extension, simply go click on the Extension icon in the right taskbar in VSCode and search for "Espressif IDF". Click install.

Full installation and setup instructions be [found here](https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/install.md).

## 5. Setting up ESP-IDF
Once in the extensions section, press the settings wheel (the one in the side menu), select ```Install Another Version``` and pick **1.6.1** .

After installation, a setup wizard will appear. It can also be opened by searching for **ESP-IDF: Configure ESP-IDF extension** in the Command Palette (accessible through the top search bar).

Choose the "Express" option. When prompted to do so, select **ESP-IDF version v4.4**. You can leave everything else default. Wait until the setup wizard displays a message stating that settings have been configured.

## 6. Using the repo
The Arduino Core means that code can be written for the ESP32 just like you would for any Arduino board. To do this, use the `setup()` and `loop()` methods found in `arduino_main.cpp`.

To build for the ESP32, click the "Build Project" button (cylinder) in the bottom taskbar.

To flash onto an ESP32, click the "Flash Project" button (lightning bolt) in the bottom taskbar.

To read serial output coming from the ESP32, click the "Monitor Device" button (monitor) in the bottom taskbar.

## 7. What to do if your stuff don't work

* Make sure your extension is on version **Version 1.6.1**
* Go to esp/esp-idf location (in windows terminal), run 
```sh
.\install.bat
```
after that run 
```sh
.\export.bat
```
You may be required to install [Python](https://www.python.org/downloads/) **make sure you click add to path** or [Git](https://git-scm.com/downloads)

* If your extension installed but doesn't build due to a linker issue, Go to .espressif\python_env\idf4.4_py3.8_env\Scripts and run
```sh
pip uninstall pyparsing
```
```sh
pip install pyparsing==2.2.0
```
If all else fails then uninstall the Espressif extension and delete the ```.espressif``` and ```esp``` folder from your computer. Download the espressif nightly build from this [link](https://nightly.link/espressif/vscode-esp-idf-extension/workflows/ci/master/esp-idf-extension.vsix.zip) and unzip it in whatever location you want.  
In Visual Studio Code press ```CTRL```+```Shift```+```P``` and type in ```VSIX``` then select the install from VSIX option and select the file you unzipped. The esp-idf configuration menu should open where you should then follow the same installation instructions as before.
