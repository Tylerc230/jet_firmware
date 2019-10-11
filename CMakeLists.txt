# Define CMake's minimum version (must-do) and the project's name and supported languages
cmake_minimum_required(VERSION 3.8.2)
project(Jet_LEDs LANGUAGES C CXX ASM)

# Call a framework utility function, passing it information about the hardware board that will be used - This function returns a structure known only to the framework
get_board_id(board_id pro 16MHzatmega328)
# Create an executable suitable for Arduino using CMake-style target-creation
add_arduino_executable(Jet_LEDs ${board_id} jet_leds.cpp inputs.cpp inputs.h leds.cpp leds.h constants.h)
find_arduino_library(fastled FastLED ${board_id} 3RD_PARTY)
link_arduino_library(Jet_LEDs fastled ${board_id})
# Upload the created target through a connected Serial Port (Where your board is connected to)
upload_arduino_target(Jet_LEDs "${board_id}" COM3)
