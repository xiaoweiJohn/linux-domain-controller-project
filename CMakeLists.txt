cmake_minimum_required(VERSION 3.10)


# 项目名称
project(Vehicle_Domain_Controller)


# C++版本
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED ON)



################################################
# 头文件路径
################################################


include_directories(

    include

    include/can

    include/ecu

    include/middleware

    include/common

)



################################################
# 源文件
################################################


set(SOURCE_FILES


    src/main.cpp


    # ECU模块

    src/ecu/sensor_ecu.cpp

    src/ecu/body_ecu.cpp

    src/ecu/battery_ecu.cpp



    # CAN模块

    src/can/can_pack.cpp

    src/can/can_unpack.cpp

    src/can/can_filter.cpp



    # Middleware

    src/middleware/message_queue.cpp


)



################################################
# 生成可执行文件
################################################


add_executable(

    vehicle_controller

    ${SOURCE_FILES}

)



################################################
# Linux线程库
################################################


target_link_libraries(

    vehicle_controller

    pthread

)


