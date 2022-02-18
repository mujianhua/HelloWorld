#include <iostream>
using namespace std;
int main()
{
    int a = 123;
    auto f = [a]()mutable { cout << ++a; }; // 不会报错
    cout << a << endl; // 输出：123
    f(); // 输出：124
}
//在Lambda表达式中，如果以传值方式捕获外部变量，则函数体中不能修改该外部变量
//否则会引发编译错误。那么有没有办法可以修改值捕获的外部变量呢？
//这是就需要使用mutable关键字,
//该关键字用以说明表达式体内的代码可以修改值捕获的变量