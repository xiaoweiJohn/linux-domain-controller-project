cmake_minimum_required(VERSION 3.10)

project(vehicle_controller)


set(CMAKE_CXX_STANDARD 14)


include_directories(include)


add_executable(
vehicle_controller

src/main.cpp

src/sensor.cpp

src/body.cpp

src/message_queue.cpp

)
