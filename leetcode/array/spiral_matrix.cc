#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /* 59. 螺旋矩阵 II */
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int start_x = 0, start_y = 0;
    int count = 1;  // 矩阵中的数值
    int loop = n / 2;
    int offest = 1;  // 每条边遍历的长度 n-offest
    int i, j;
    while (loop--) {
      i = start_x;
      j = start_y;
      for (j = start_y; j < n - offest; j++) {
        res[start_x][j] = count++;
      }
      for (i = start_x; i < n - offest; i++) {
        res[i][j] = count++;
      }
      for (; j > start_y; j--) {
        res[i][j] = count++;
      }
      for (; i > start_x; i--) {
        res[i][j] = count++;
      }
      start_x++;
      start_y++;
      offest++;
    }
    if (n % 2 == 1) {
      res[n / 2][n / 2] = count;
    }
    return res;
  }
};

int main() {
  Solution s;
  auto res = s.generateMatrix(5);
  for (size_t i = 0; i < res.size(); i++) {
    for (size_t j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << '\t';
    }
    cout << '\n';
  }
  return 0;
}
