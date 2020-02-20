cmake_minimum_required(VERSION 3.15)
project(coap_retransmit)

set(CMAKE_CXX_STANDARD 11)

add_library(coap-simple coap-simple.cpp coap-simple.h)
add_library(coap_retransmit coap_retransmit.cpp coap_retransmit.h)