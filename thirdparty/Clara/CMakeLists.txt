project(clara_lib VERSION 0.0 LANGUAGES CXX)

add_library(clara INTERFACE)
target_include_directories(clara INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
