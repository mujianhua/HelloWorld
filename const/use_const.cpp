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

void function() {
  char greeting[] = "Hello";
  char* p1 = greeting;  // 指针变量,指向字符数组变量
  p1[1] = 'h';
  std::cout << p1 << '\n';
  const char* p2 =
      greeting;  // 指针变量,指向字符数组常量(const后面的是char,说明指向的字符(char)不可改变)
  // p2[1] = 'h';  error
  char* const p3 =
      greeting;  // 自身是常量的指针,指向字符数组变量(const后面是p3,
                 // 说明p3指针自身不可改变)
  p3[4] = 'l';
  std::cout << p3 << '\n';
  const char* const p4 = greeting;  // 自身是常量的指针,指向字符数组常量
}

void function2(const int var);    // 传递进来的参数在函数内不可变
void function3(const char* var);  // 参数指针所指内容为常量
void function4(char* const var);  // 参数指针为常量
void function5(const int& var);   // 引用在函数内为常量

int main() {
  A b(1);
  const A a(2);  // 常对象,只能调用常成员函数
  a.getValue();

  function();
}