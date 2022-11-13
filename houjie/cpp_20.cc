#include <bitset>
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

namespace mjh001 {
void print() { std::cout << "final print()" << '\n'; }

// Variadic Templates
// 数量不定的模板参数
// 递归 逐一分解处理
template <typename T, typename... Types>
void print(const T &firstArg, const Types &...args) {
  std::cout << firstArg << '\n';
  // sizeof...(args);
  print(args...);
}
template <typename... Types>
void print(const Types &...args) {}
// 上述两种Templates怎么调用??

void test_print() { print(7.5, "hello", std::bitset<16>(377), 42); }

// tuple

}  // namespace mjh001

namespace mjh002 {
// NULL;     // 0
// nullptr;  // void*
}  // namespace mjh002

namespace mjh003 {
// uniform initialization {}   initilizer_list<T>
std::vector<int> v{2, 3, 4, 9, 70, 80};
std::vector<std::string> cities{"beijing", "london"};

void print(std::initializer_list<int> vals) {
  for (auto p = vals.begin(); p != vals.end(); ++p) {
    std::cout << *p << '\n';
  }
}

void test() { print({1, 2, 3, 6, 9}); }
}  // namespace mjh003

// TODO:...
namespace mjh004 {

// alias template + template template parameter
template <typename T>
using Vec = std::vector<T, std::allocator<T>>;

template <typename T, template <class> class Container>
class XCls {
 public:
  XCls() {  // ctor
    int SIZE = 100;
    for (long i = 0; i < SIZE; ++i) {
      c.insert(c.end(), T());
    }

    Container<T> c1(c);
    Container<T> c2(std::move(c));
    c1.swap(c2);
  }

 private:
  Container<T> c;
};

void test() { XCls<std::string, Vec> c1; }

}  // namespace mjh004

int main() {
  std::cout << "cpp complier version is" << __cplusplus << '\n';

  mjh004::test();
  return 0;
}
