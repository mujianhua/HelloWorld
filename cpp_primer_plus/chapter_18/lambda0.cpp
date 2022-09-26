#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

const long size1 = 39L;
const long size2 = 100 * size1;
const long size3 = 100 * size2;

bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }

int main(void) {
  std::vector<int> numbers(size1);
  std::generate(numbers.begin(), numbers.end(), std::rand);
  auto count3 = std::count_if(numbers.begin(), numbers.end(), f3);
  std::cout << count3 << '\n';
}
