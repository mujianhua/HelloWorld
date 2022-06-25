#include <iostream>

// 友元关系没有继承性
// 假如类B是类A的友元,类C继承于类A,那么友元类A是没办法直接访问类C的私有或保护成员

// 友元关系没有传递性
// 假如类B是类A的友元，类C是类B的友元，那么友元类C是没办法直接访问类A的私有或保护成员，也就是不存在“友元的友元”这种关系。
class A {
 public:
  A(int _a) : a(_a) {}
  friend class B;

 private:
  int a;
  int get_aa() { return a; }
};

class B {
 public:
  int get_a(A ca) { return ca.get_aa(); }
  int get_a_(A ca) { return ca.a; }
};

int main() {
  A a(3);
  B b;
  // b.get_aa();
  std::cout << b.get_a(a) << '\n';
  std::cout << b.get_a_(a) << '\n';
  return 0;
}