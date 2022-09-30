#include <iostream>

class A {
 private:
  const int a;  // 常对象成员,可以使用初始化列表或者类内初始化
 public:
  // constructer
  A() : a(0){};
  A(int x) : a(x){};

  // const 可用于对重载函数的区分
  int getValue();
  int getValue() const;  // 常成员函数,常对象调用.  不得修改类中任何数据成员的值
};