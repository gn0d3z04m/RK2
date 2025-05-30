set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(singleton)
include(CTest)

include_directories("third-party/")
add_subdirectory(third-party/gtest)

add_library(singleton_class singleton_class.cpp)
add_executable(main main.cpp)
add_executable(test_s test_s.cpp)
target_link_libraries(test_s gtest gtest_main)
target_link_libraries(test_s singleton_class)

target_link_libraries(main singleton_class)

if(BUILD_TESTS)
    enable_testing()
    add_test(NAME test_s COMMAND test_s)
endif()

install(TARGETS main
    RUNTIME DESTINATION bin
    CONFIGURATIONS Release
    DESTINATION bin
    COMPONENT bin
)

add_custom_target(packageBin
  COMMAND cpack 
    -D CPACK_GENERATOR="DEB"
    -D CPACK_COMPONENTS_ALL=bin
)

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your name")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>=2.28), zlib1g")
set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_COMPONENTS_ALL bin)
set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)
include(CPack)
