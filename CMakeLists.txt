cmake_minimum_required(VERSION 3.10.0)
project(template)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
include_directories(include)
file(GLOB MAIN
        "src/*.c"
        "include/*.h"
    )
    add_executable(executable ${MAIN})
