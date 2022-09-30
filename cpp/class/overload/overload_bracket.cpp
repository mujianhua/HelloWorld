#include <cstring>
#include <iostream>

using namespace std;

struct Person {
    double salary;
    char *name;
};

class SalaryManage {
  private:
    Person *employ;
    int max; // 数组下标上界
    int n;   // 数组中的实际职工数
  public:
    SalaryManage(int Max = 0) {
        max = Max;
        n = 0;
        employ = new Person[max];
    }
};