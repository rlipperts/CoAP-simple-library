cmake_minimum_required(VERSION 3.15)
project(coap_retransmit)

# C++ level 11 required for std::thread and std::chrono
set(CMAKE_CXX_STANDARD 11)

add_library(coap-simple coap-simple.cpp coap-simple.h)

# includes esp-32 libraries into library search path
include_directories(~/workspace/esp32-lib/cores/esp32)