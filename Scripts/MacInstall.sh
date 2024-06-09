#!/bin/bash

# Script made using guide from ESPRESSIF:
# https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-macos-setup.html#step-1-install-prerequisites

# Function to install homebrew
install_homebrew() {

    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
}

# Function to install prerequisites
install_prerequisites() {

    # Install ninja build systems
    brew install cmake ninja dfu-util

    brew install ccache

    # Install XCode command line tools
    xcode-select --install
}

# Function to install Python 3
install_python3() {

    # Install Python 3 using HomeBrew
    brew install python3

    # Navigate to the Python folder
    #cd /Applications/Python3/

}

# Function to clone ESP-IDF repository
clone_esp_idf() {

    # Create directory for ESP-IDF
    mkdir -p ~/esp
    cd ~/esp

    # Clone ESP-IDF repository
    git clone --recursive https://github.com/espressif/esp-idf.git
}

# Function to set up tools
setup_tools() {

    # Change directory to ESP-IDF
    cd ~/esp/esp-idf

    # Run install script
    ./install.sh all

    # Run export script
    . ./export.sh
}

# Compiles an esp-idf examples
test_compile(){

    # Change directory to Blink example
    cd ~/esp/esp-idf/examples/get-started/blink

    # Builds project
    idf.py build
}

main() {
    # Intstall homebrew
    install_homebrew

    # Install prerequisites
    install_prerequisites

    # Install Python 3
    install_python3

    # Clone ESP-IDF repository
    clone_esp_idf

    # Set up tools
    setup_tools

    # Build blink example
    test_compile

    echo "If you see project build complete, you're done!"

}

main