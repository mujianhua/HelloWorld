/**
 * @file
 * @brief 重载小括号
 */

#include <iostream>
using namespace std;

class Time {
  public:
    Time(int h, int m, int s) : hh(h), mm(m), ss(s) {}

    void operator()(int h, int m, int s) {
        hh = h;
        mm = m;
        ss = s;
    }

    void showTime() { cout << hh << ":" << mm << ":" << ss << '\n'; }

  private:
    int hh, mm, ss;
};

int main() {
    Time t1(10, 10, 10);
    t1.showTime();
    t1(5, 5, 5);
    t1.showTime();
    return 0;
}