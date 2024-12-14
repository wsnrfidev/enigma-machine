cmake_minimum_required(VERSION 3.10)

# Project Name
project(Enigma)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add all the source files required to build the executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Rotor.cpp
    src/RotorData.cpp
    src/Reflector.cpp
    src/Plugboard.cpp
    src/Enigma.cpp
    src/EnigmaApp.cpp
)

