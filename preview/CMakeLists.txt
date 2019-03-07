project(preview_prg VERSION 0.0 LANGUAGES CXX)

add_executable(preview preview.cpp)
target_link_libraries(preview PRIVATE fmt clara)
