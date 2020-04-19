cmake_minimum_required(VERSION 3.11)
project(termcolor_top VERSION 0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE release)
endif()

enable_testing()

add_subdirectory(thirdparty)
add_subdirectory(libcolor)
add_subdirectory(preview)
add_subdirectory(test)
