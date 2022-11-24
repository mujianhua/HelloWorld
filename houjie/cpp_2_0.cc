#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bitset>
#include <ctime>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <typeinfo>
#include <vector>

/**
 * \brief Variadic Templates  数量不定的模板参数
 * 递归 逐一分解处理
 */
namespace mjh001 {

void print() { std::cout << "final print()" << '\n'; }

template <typename T, typename... Types>
void print(const T &firstArg, const Types &...args) {
  std::cout << firstArg << '\n';
  // sizeof...(args);
  print(args...);
}

template <typename... Types>
void print(const Types &...args) {}
// 上述两种Templates怎么调用??
// A: 比较谁更泛化，谁更特化。

void test_print() { print(7.5, "hello", std::bitset<16>(377), 42); }

// 重写 printf

// maximum 1
int maximum(int n) { return n; }

template <typename... Args>
int maximum(int n, Args... args) {
  return std::max(n, maximum(args...));
}

void test_maximum() { std::cout << maximum(57, 68, 69, 100, 20, 18) << '\n'; }

// maximum 2

/**
 * \brief 以异于一般的方式处理 first 元素和 last 元素
 * 和函数顺序有关系...
 */
template <int IDX, int MAX, typename... Args>
struct PRINT_TUPLE {
  static void print(std::ostream &os, const std::tuple<Args...> &t) {
    os << std::get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
    PRINT_TUPLE<IDX + 1, MAX, Args...>::print(os, t);
  }
};

template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...> {
  static void print(std::ostream &os, const std::tuple<Args...> &t) {}
};

template <typename... Args>
std::ostream &operator<<(std::ostream &os, const std::tuple<Args...> &t) {
  os << "[";
  PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t);
  return os << "]";
}

void test_first_last_print() {
  std::cout << std::make_tuple(7.5, std::string("hello"), std::bitset<16>(377),
                               42);
}

/**
 * \brief tuple
 */
template <typename... Values>
class tuple;
template <>
class tuple<> {};

template <typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...> {
  typedef tuple<Tail...> inherited;

 public:
  tuple() {}
  tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {}

  Head head() { return m_head; }

  // todo: 和返回类型有关系 看PPT p88
  // this 指向的是尾端
  inherited &tail() { return *this; }

 protected:
  Head m_head;
};

void test_tuple() {
  tuple<int, float, std::string, std::string> t(41, 6.3, "hello", "world");
  std::cout << t.head();
  auto tmp = t.tail();
  std::cout << t.tail().head();
}

}  // namespace mjh001

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

namespace mjh005 {
// Type Alias
// typedef void (*func)(int, int);
using func = void (*)(int, int);

// this name 'func' now denotes a pointer to function
void example(int, int) { std::cout << "func example\n"; }

void test() {
  func fn = example;
  fn(1, 1);
}

template <typename T>
struct Container {
  using value_type = T;
};

}  // namespace mjh005

namespace mjh006 {

template <typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y) {
  return x + y;
}

// metaprograming
// T是容器
// template <typename T>
// void test_decltype(T obj) {
//   typedef typename decltype(obj)::iterator iType;
// }

}  // namespace mjh006

/**
 * \brief Lambda
 */
namespace mjh007 {
auto L = [] { std::cout << "hello lambda\n"; };

void test_lambda() {
  // 直接调用
  [] { std::cout << "hello lambda\n"; }();

  L();
}
}  // namespace mjh007

/**
 * \brief Rvalue references 偷资源
 */
namespace mjh008 {

class MyString {
 public:
  static size_t Dctor;  // default-ctor
  static size_t Ctor;
  static size_t CCtor;  // copy-ctor
  static size_t CAsgn;  // copy-assignment
  static size_t MCtor;  // move-ctor
  static size_t MAsgn;  // move-assignment
  static size_t Dtor;

 private:
  char *_data;
  size_t _len;
  void _init_data(const char *s) {
    _data = new char[_len + 1];
    memcpy(_data, s, _len);
    _data[_len] = '\0';
  }

 public:
  // default ctor
  MyString() : _data(nullptr), _len(0) { ++Dctor; }

  // ctor
  MyString(const char *p) : _len(strlen(p)) {
    ++Ctor;
    _init_data(p);
  }

  // copy ctor
  MyString(const MyString &str) : _len(str._len) {
    ++CCtor;
    _init_data(str._data);  // copy
  }

  // move ctor
  MyString(MyString &&str) noexcept : _data(str._data), _len(str._len) {
    ++MCtor;
    str._len = 0;
    str._data = nullptr;
  }

  // copy assignment
  MyString &operator=(const MyString &str) {
    ++CAsgn;
    if (this != &str) {
      if (_data) delete _data;
      _len = str._len;
      _init_data(str._data);  // copy
    }
    return *this;
  }

  // move assignment
  MyString &operator=(MyString &&str) noexcept {
    ++MAsgn;
    if (this != &str) {
      if (_data) delete _data;
      _len = str._len;
      _data = str._data;
      str._len = 0;
      str._data = nullptr;
    }
    return *this;
  }

  // Dtor
  virtual ~MyString() {
    ++Dctor;
    if (_data) delete _data;
  }
};

size_t MyString::Dctor = 0;
size_t MyString::Ctor = 0;
size_t MyString::CCtor = 0;
size_t MyString::CAsgn = 0;
size_t MyString::MCtor = 0;
size_t MyString::MAsgn = 0;
size_t MyString::Dtor = 0;

template <typename T>
void output_static_data(const T &mystr) {
  std::cout << typeid(mystr).name() << "--" << '\n';
  std::cout << "CCtor = " << T::CCtor << ", MCtor = " << T::MCtor
            << ", Ctor = " << T::Ctor << ", Dtor = " << T::Dtor;
}
// 测试moveable
template <typename M>
void test_moveable(M c1, long &value) {
  char buf[10];
  typedef
      typename std::iterator_traits<typename M::iterator>::value_type V1type;
  std::clock_t time_start = std::clock();
  for (long i = 0; i < value; ++i) {
    // !sprintf(buf, 10, "%d", rand());
    buf[0] = 'a';
    buf[1] = 'a';
    buf[2] = 'a';
    buf[3] = 'a';
    auto iter = c1.end();
    auto tmp = V1type(buf);
    c1.insert(iter, std::move(tmp));
  }
  std::cout << "construction, milli-seconds: " << (std::clock() - time_start)
            << '\n';
  std::cout << "size(): " << c1.size() << '\n';
  output_static_data(*(c1.begin()));
}

void test() {
  long value = 100000;
  test_moveable(std::vector<MyString>(), value);
}

}  // namespace mjh008

int main() {
  std::cout << "cpp complier version is " << __cplusplus << '\n';

  mjh001::test_tuple();
  return 0;
}
