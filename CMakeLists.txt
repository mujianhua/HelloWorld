cmake_minimum_required(VERSION 3.0.0)
project(HelloWorld VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./out/bin)

#add_executable(multi_threading multi_threading/multi_threading_mutex.cpp)
#target_link_libraries(multi_threading pthread)

#add_executable(lambda0 cpp_primer_plus/chapter_18/lambda0.cpp)

#include_directories(leetcode/linked_list)
#add_executable(leetcode leetcode/tree/tree.cc)

add_executable(cpp_20 houjie/cpp_2_0.cc)

# add_executable(test_bind cpp/bind.cc)