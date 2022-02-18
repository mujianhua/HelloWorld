#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
// bool fun7(int x)
//{
//	return x%13==0;
// }
int main() {
  vector<int> vec(10);
  generate(vec.begin(), vec.end(), rand);
  for (int i = 0; i < 10; i++) cout << vec[i] << "  ";
  cout << endl;
  int count =
      count_if(vec.begin(), vec.end(),
               [](int x) { return x % 7 == 0; }  //使用lambda表达式替换fun7函数
      );
  cout << count << endl;

  return 0;
}
