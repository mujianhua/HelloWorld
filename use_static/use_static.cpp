#include <iostream>

int f1() {
  // 静态局部变量
  // 程序执行到该对象是会被首次初始化
  static int i = 0;
  i += 1;
  return i;
}

extern int a;  // 使用其他文件中的变量n

void fn() {
  a++;
  std::cout << a;
}

class Rectangle {
 private:
  int m_w, m_h;
  static int s_sum;  // ISO C++ forbids in-class initialization of non-const
                     // static member 'Rectangle::s_sum'

 public:
  Rectangle(int w, int h) {
    this->m_w = w;
    this->m_h = h;
    s_sum += (this->m_w + this->m_h);  // 静态数据函数
  }

  void getsum() { std::cout << s_sum << '\n'; }

  static void getsum1() { std::cout << s_sum << '\n'; }  // 静态成员函数
  // 静态成员函数不能访问非静态(包括成员函数和数据成员),但是非静态可以访问静态
  // 因为静态是属于类的,它是不知道你创建了10个还是100个对象,
  // 所以它对你对象的函数或者数据是一无所知的,所以它没办法调用,
  // 而反过来,你创建的对象是对类一清二楚的(不然你怎么从它那里实例化呢),
  // 所以你是可以调用类函数和类成员的,就像不管GetSum是不是static,
  // 都可以调用static的s_sum一样
};

int Rectangle::s_sum = 0;

int main() {
  // int a = f1();
  // int b = f1();
  // std::cout << "a : " << a << '\n';
  // std::cout << "b : " << b << '\n';

  // std::cout << a << '\n';
  // fn();

  Rectangle r1(10, 10);
  r1.getsum();
  r1.getsum1();
  Rectangle r2(1, 1);
  r2.getsum();
  r2.getsum1();

  return 0;
}