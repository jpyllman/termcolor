cmake_minimum_required(VERSION 3.11)
project(termcolor_top VERSION 0.0 LANGUAGES CXX)

option(ENABLE_TESTING "Enable Test Builds" ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE release)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -strip")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")

add_subdirectory(thirdparty)
add_subdirectory(libcolor)
add_subdirectory(preview)

if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()
