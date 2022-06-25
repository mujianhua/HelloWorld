#include <iostream>

class base {
 public:
  virtual void show() = 0;
  int getX() { return x; }
  base(int i) : x(i) {}  // 抽象类可以有构造函数
  virtual ~base() { std::cout << "destructor base\n"; }

 private:
  int x;
};

class derived : public base {
 public:
  void show() { std::cout << "I'm detived!\n"; }
  derived(int x) : base(x) {}
};

int main() {
  base *bp = new derived(3);
  bp->show();
  std::cout << bp->getX() << '\n';
  delete bp;
  return 0;
}