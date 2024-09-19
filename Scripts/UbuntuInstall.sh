#!/bin/bash

# Function to install prerequisites
install_prerequisites() {
    sudo apt-get update
    sudo apt-get install -y git wget flex bison gperf python3 python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
}

# Function to install ESP-IDF
install_esp_idf() {
    # Create directory for ESP-IDF
    mkdir -p ~/esp
    cd ~/esp

    # Clone ESP-IDF repository
    git clone --recursive https://github.com/espressif/esp-idf.git
}

# Function to set up the tools
setup_tools() {
    # Change directory to ESP-IDF
    cd ~/esp/esp-idf

    # Run install script for ESP32
    ./install.sh esp32

     # Run export script
    . ./export.sh
}

# Main function
main() {
    # Install prerequisites
    install_prerequisites

    # Install ESP-IDF
    install_esp_idf

    # Set up the tools
    setup_tools
}

# Execute main function
main
