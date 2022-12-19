#include <functional>
#include <iostream>

/* 1.std::bind绑定普通函数 */
double callableFunc(double x, double y) { return x / y; }
void test_bind_1()
{
  auto NewCallable = std::bind(callableFunc, std::placeholders::_1, 2);
  std::cout << NewCallable(20);
}

/* 2.std::bind绑定一个成员函数 */


int main()
{
  test_bind_1();
  return 0;
}
