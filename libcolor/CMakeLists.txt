project(color_lib VERSION 0.0 LANGUAGES CXX)

add_library(libcolor STATIC libcolor.cpp libcolor.hpp)
target_include_directories(libcolor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
