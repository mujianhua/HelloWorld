#include <iostream>
using namespace std;
int main()
{
    int a = 123;
    auto f = [&a] { cout << a << endl; }; 
    a = 321;
    f(); // 输出：321
}
//使用引用捕获一个外部变量，只需要在捕获列表变量前面加上一个引用说明符&
//引用捕获的变量使用的实际上就是该引用所绑定的对象