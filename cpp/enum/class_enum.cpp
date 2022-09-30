#include <iostream>
using namespace std;

class A
{
  public:
    // const int size = 100; // error 企图在类声明中初始化 const 数据成员
    // int a[size];          // error 未知的 SIZE
};

/**
 * @brief 正确应该在类的构造函数的初始化列表中进行 const 赋值
 */
class A1
{
    A1(int size); // 构造函数
    const int SIZE;
};
A1::A1(int size) : SIZE(size) // 构造函数的定义
{
}

/**
 * @brief 建立整个类中都恒定的常量，而不是对象中的常量
 */

class Person
{
  public:
    typedef enum
    {
        boy = 0,
        gril
    } sextype;
};

int main()
{
    Person p1;
    cout << p1.gril << '\n';
    cout << Person::gril << '\n';
    return 0;
}
