# Use an official ESP-IDF image
FROM espressif/idf:latest

# Set the working directory
WORKDIR /esp

# Copy the project files into the container
COPY . /esp

# Set environment variables
ENV IDF_PATH=/opt/esp/idf

# Install additional dependencies if needed
RUN apt-get update && apt-get install -y \
    git \
    wget \
    flex \
    bison \
    gperf \
    python3 \
    python3-pip \
    python3-setuptools \
    cmake \
    ninja-build \
    ccache \
    libffi-dev \
    libssl-dev \
    dfu-util \
    libusb-1.0-0 \
    udev

# Source the ESP-IDF export script
RUN /bin/bash -c "source $IDF_PATH/export.sh"