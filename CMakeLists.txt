cmake_minimum_required(VERSION 3.28)
project(chess)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(include)
file(GLOB_RECURSE src "src/*")
add_library(myLibrary ${src})

include_directories(tests_include)
file(GLOB_RECURSE src_tests "tests_src/*")
add_library(myTestsLibrary ${src_tests})

add_executable(start_game main.cpp)
target_link_libraries(start_game myLibrary sfml-graphics sfml-window sfml-system)

add_executable(MyTests tests_src/test.cpp)
target_link_libraries(MyTests ${GTEST_BOTH_LIBRARIES} myTestsLibrary myLibrary -lgtest_main pthread sfml-graphics sfml-window sfml-system)


enable_testing()
add_test(AllTests MyTests Command MyTests)
