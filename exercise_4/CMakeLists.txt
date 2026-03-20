cmake_minimum_required(VERSION 3.10)

project(HUDDisplay)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories(${OPENCV_INCLUDE_DIRS})

add_executable(HUDDisplaysushant main.cpp)

target_link_libraries(HUDDisplaysushant ${OpenCV_LIBS})