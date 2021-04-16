cmake_minimum_required(VERSION 3.13)

project(face_detection)

find_package(OpenCV REQUIRED)
find_library(wiringPi_LIB wiringPi)

add_executable(face_detection face_detection.cpp)

target_link_libraries(face_detection 
    ${OpenCV_LIBS}
    pthread
    ${wiringPi_LIB}
    python3.7m
    )


