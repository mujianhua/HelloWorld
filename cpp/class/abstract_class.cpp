#include <iostream>

// 抽象类中: 在成员函数中可以调用纯虚函数,
// 在构造函数/析构函数内部不能使用纯虚函数

// 如果一个类从抽象类派生而来, 它必须实现了基类中所有的纯虚函数,
// 才能成为非抽象类

class A { // 抽象类
  public:
    virtual void f(); // 纯虚函数
    void g() { this->f(); }
    A() {}

  protected:
    int b = 0;

  private:
    int a;
};

class B : public A {
  public:
    void f() { std::cout << "B:f()\n"; }

    int get_b() { return b; }

    // int get_b1() {
    //     A a;
    //     return a.b;
    // }
};

int main() {
    B b;
    b.f();
    b.g();
    return 0;
}