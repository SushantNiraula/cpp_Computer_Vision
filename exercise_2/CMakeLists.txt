cmake_minimum_required(VERSION 3.10)

# Name your project
project(WebcamFeedTest)

# Require C++ 14 or higher (standard for modern OpenCV)
set(CMAKE_CXX_STANDARD 14)

# Find the OpenCV package installed by Homebrew
find_package(OpenCV REQUIRED)

# Tell CMake to include the OpenCV header directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Create an executable from your main.cpp file
add_executable(WebcamFeedTest main.cpp)

# Link the pre-compiled OpenCV libraries to your executable
target_link_libraries(WebcamFeedTest ${OpenCV_LIBS})