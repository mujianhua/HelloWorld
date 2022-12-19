#include <iostream>
using std::cout;

// 泛化之后 再进行特化
template <class type>
struct __type1
{
};
template <>
struct __type1<int>
{
};
template <>
struct __type1<double>
{
};

// 泛化 偏特化
template <class T, class Alloc>
class __type2
{
};
template <class Alloc>
class __type2<bool, Alloc>
{
};

template <class T>
class __type3
{
};
template <class T>
class __type3<T *>
{
};
template <class T>
class __type3<const T *>
{
};

int main() { return 0; }
