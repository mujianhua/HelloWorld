
#include <vector>

using namespace std;

// 冒泡排序
void BubbleSort(vector<int> &v) {
  int len = v.size();
  for (int i = 0; i != len - 1; ++i) {
    for (int j = 0; j < len - 1 - i; ++j) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
}

// 冒泡排序(改进版)
void BubbleSort_orderly(vector<int> &v) {
  int len = v.size();
  bool orderly = false;
  for (int i = 0; i != len - 1 && !orderly; ++i) {
    orderly = true;
    for (int j = 0; j != len - 1 - i; ++j) {
      if (v[j] > v[j + 1]) {
        orderly = false;
        swap(v[j], v[j + 1]);
      }
    }
  }
}
