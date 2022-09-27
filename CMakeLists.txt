cmake_minimum_required(VERSION 3.0.0)
project(cpp VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE "Debug")

include_directories(csv)
include_directories(const)
include_directories(smart_ptr)

add_executable(multi_threading multi_threading/multi_threading_mutex.cpp)
target_link_libraries(multi_threading pthread)

add_executable(lambda0 cpp_primer_plus/chapter_18/lambda0.cpp)

add_executable(leetcode leetcode/array/double_ptr.cc)