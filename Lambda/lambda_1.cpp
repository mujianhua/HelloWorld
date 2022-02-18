#include <iostream>
using namespace std;
int main() {
  int a = 123;
  auto f = [a] { cout << a << endl; };
  a = 321;
  f();  // 输出：123
}
// 如果以传值方式捕获外部变量，则在Lambda表达式函数体中不能修改该外部变量的值