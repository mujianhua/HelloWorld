#include <iostream>
using namespace std;
class A {
 private:
  int a;

 public:
  A(int para) : a(para) {}
  void update(int para) { a = para; }
  void show() { cout << a << '\n'; }
};

int main() {
  A obj(5);
  obj.show();
  obj.update(10);
  obj.show();
}