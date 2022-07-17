#include <iostream>
using namespace std;

class A {
  private:
    int a;

  public:
    virtual void show() = 0; // 纯虚函数
};

int main() {
    A a;             // error 抽象类不能创建对象
    A *a1;           // 可以创建抽象类的指针
    A *a2 = new A(); // error 抽象类不能创建对象
    return 0;
}