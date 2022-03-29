cmake_minimum_required(VERSION 3.0.0)
project(cpp_learning VERSION 0.1.0)

# 设置静态库文件目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
# 动态库文件目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)
# 可执行文件目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -Wall")
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE "Debug")

# add_executable(my-test-prpject main.cpp)
# add_executable(pthread1 ${CMAKE_SOURCE_DIR}/pthread/muti_thread_test_1.cpp)
# add_executable(test-lambda Lambda/lambda_1.cpp)
add_executable(test_class class/class_1.cpp)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})





# note:
# set - 显式的定义变量  
# 定义SRC变量，其值为main.cpp hello.cpp
# set(SRC sayhello.cpp hello.cpp)

# include_directories - 向工程添加多个特定的头文件搜索路径  --->相当于指定g++编译器的-I参数
# 将/usr/include/myincludefolder 和 ./include 添加到头文件搜索路径
# include_directories(/usr/include/myincludefolder ./include)

# link_directories - 向工程添加多个特定的库文件搜索路径  --->相当于指定g++编译器的-L参数
# 将/usr/lib/mylibfolder 和 ./lib 添加到库文件搜索路径
# link_directories(/usr/lib/mylibfolder ./lib)

# add_library - 生成库文件
# 通过变量 SRC 生成 libhello.so 共享库
# add_library(hello SHARED ${SRC})

# target_link_libraries - 为 target 添加需要链接的共享库  --->相同于指定g++编译器-l参数
# 将hello动态库文件链接到可执行文件main
# target_link_libraries(main hello)

# 在CMAKE_CXX_FLAGS编译选项后追加-std=c++11
# set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")