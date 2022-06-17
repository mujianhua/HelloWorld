#include <iostream>
#include <limits>
int main(int, char**) {
  std::cout << "Hello, world!\n";
  double min = std::numeric_limits<double>::max();
  std::cout << min << '\n';
}
