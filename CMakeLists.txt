# The following lines of boilerplate have to be in your project's CMakeLists
# in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.13)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}) 
set(BTSTACK_ROOT ${PROJECT_ROOT}/components/bluepad32/external/btstack)

# component dir is already in path by default
set(EXTRA_COMPONENT_DIRS ${PROJECT_ROOT}/components/bluepad32/src/components ${PROJECT_ROOT}/components/bluepad32/external/btstack/platform/embedded) #special bp32 thing idk



include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(bluepad32_esp32_example_app)