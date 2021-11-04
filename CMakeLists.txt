cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(hardwarek_project C CXX ASM)
set(CMAKE_C_STANDART 11)
set(CMAKE_CXX_STANDART 17)
pico_sdk_init()

add_executable(hardware
    ../src/raspberrypi/hardware.c
    ../src/PC/software.c
    )
pico_enable_stdio_usb(hardware 1)
#pico_enable_stdio_uart(hardare 0)

pico_add_extra_outputs(hardware)

target_link_libraries(hardare pico_stdlib)
