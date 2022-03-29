# const

## const对象默认为文件局部变量
非const变量默认为extern。要使const变量能够在其他文件中访问，必须在文件中显式地指定它为extern。
1. 未被const修饰的变量在不同文件的访问
```c++
// file1.cpp
int ext
// file2.cpp
#include<iostream>

extern int ext;
int main(){
    std::cout<<(ext+10)<<std::endl;
}
```  
2. const常量在不同文件的访问
```c++
//extern_file1.cpp
extern const int ext=12;
//extern_file2.cpp
#include<iostream>
extern const int ext;
int main(){
    std::cout<<ext<<std::endl;
}
```

## 指针与const

```c++
const char * a; //指向const对象的指针或者说指向常量的指针。
char const * a; //同上
char * const a; //指向类型对象的const指针。或者说常指针、const指针。
const char * const a; //指向const对象的const指针。
```
* 如果const位于``*``的左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量；
* 如果const位于``*``的右侧，const就是修饰指针本身，即指针本身是常量。
