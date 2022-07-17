# Learning C plus plus`

email: jianhua_mu@163.com

# C++ Primer

## chapter 1

## chapter 2

```c++
int* p1, p2 // p1 是指向int的指针，p2 是int
```

多文件共享``const``对象
```c++
// file1.cpp
extern const int bufSize = fcn();
// file1.h
extern const int bufSize;
```


# DSA




# CMake
```cmake
# 设置静态库文件目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)

# 动态库文件目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)

# 可执行文件目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

# set - 显式的定义变量
# 定义SRC变量，其值为main.cpp hello.cpp
set(SRC sayhello.cpp hello.cpp)

# include_directories - 向工程添加多个特定的头文件搜索路径  --->相当于指定g++编译器的-I参数
# 将/usr/include/myincludefolder 和 ./include 添加到头文件搜索路径
include_directories(/usr/include/myincludefolder ./include)

# link_directories - 向工程添加多个特定的库文件搜索路径  --->相当于指定g++编译器的-L参数
# 将/usr/lib/mylibfolder 和 ./lib 添加到库文件搜索路径
link_directories(/usr/lib/mylibfolder ./lib)

# add_library - 生成库文件
# 通过变量 SRC 生成 libhello.so 共享库
add_library(hello SHARED ${SRC})

# target_link_libraries - 为 target 添加需要链接的共享库  --->相同于指定g++编译器-l参数
# 将hello动态库文件链接到可执行文件main
target_link_libraries(main hello)

# 在CMAKE_CXX_FLAGS编译选项后追加-std=c++11
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
```

