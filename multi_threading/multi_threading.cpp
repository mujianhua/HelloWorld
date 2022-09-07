#include <iostream>
#include <thread>

void foo(int z) {
    for (int i = 0; i < z; i++) {
        std::cout << "函数指针\n";
    }
}

class Thread_obj {
  public:
    void operator()(int x) {
        for (int i = 0; i < x; i++) {
            std::cout << "函数对象\n";
        }
    }
};

int main() {

    std::thread th1(foo, 10);
    std::thread th2(Thread_obj(), 2);

    th2.join();
    std::cout << "thread 2 done.\n";

    th1.join();
    std::cout << "thread 1 done.\n";

    return 0;
}