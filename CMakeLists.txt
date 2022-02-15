cmake_minimum_required(VERSION 3.0.0)
project(my-test-prpject VERSION 0.1.0)

enable_testing()

add_executable(my-test-prpject main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
