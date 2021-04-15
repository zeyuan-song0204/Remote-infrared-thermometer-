cmake_minimum_required(VERSION 3.13)

project(face_detection)

find_package(OpenCV REQUIRED)
find_library(wiringPi_LIB wiringPi)
find_package(Threads)
find_package(PythonLibs REQUIRED)

add_executable(face_detection face_detection.cpp)

target_link_libraries(face_detection ${OpenCV_LIBS})
target_link_libraries(face_detection ${wiringPi_LIB})
target_link_libraries(face_detection ${CMAKE_THREAD_LIBS_INIT})
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(face_detection ${PYTHON_LIBRARIES})
