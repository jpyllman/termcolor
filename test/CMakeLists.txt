project(termcolor_tests VERSION 0.0 LANGUAGES CXX)

add_executable(tst_libcolor tst_libcolor.cpp)
target_link_libraries(tst_libcolor PRIVATE libcolor Catch2)
