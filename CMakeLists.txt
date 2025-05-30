set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(singleton)
include(CTest)

add_library(singleton_class singleton_class.cpp)
add_executable(main main.cpp)
add_executable(test test.cpp)
target_link_libraries(test gtest_main)

target_link_libraries(main singleton_class)

if(BUILD_TESTS)
    enable_testing()
    add_test(NAME test COMMAND test)
endif()
