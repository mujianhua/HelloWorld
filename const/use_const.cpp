#include <use_const.h>

int A::getValue() {
  std::cout << a << '\n';
  std::cout << "there is no const\n";
  return a;
}
int A::getValue() const {
  std::cout << a << '\n';
  std::cout << "there is const\n";
  return a;
}

int main() {
  A b(1);
  const A a(2);  // 常对象,只能调用常成员函数
  a.getValue();
}