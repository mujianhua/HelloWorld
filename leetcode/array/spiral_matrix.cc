#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /* 54. 螺旋矩阵 */
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> res;
    int loop = min(rows / 2, cols / 2);
    int offset = 1;
    int start_x = 0, start_y = 0;
    int i, j;
    while (loop--) {
      i = start_x;
      j = start_y;
      for (; j < cols - offset; j++) {
        res.push_back(matrix[i][j]);
      }
      for (; i < rows - offset; i++) {
        res.push_back(matrix[i][j]);
      }
      for (; j > start_x; j--) {
        res.push_back(matrix[i][j]);
      }
      for (; i > start_y; i--) {
        res.push_back(matrix[i][j]);
      }

      offset++;
      start_x++;
      start_y++;
    }
    if (rows % 2 == 1) {
      for (j = start_x; j <= cols - offset; j++) {
        res.push_back(matrix[start_x][j]);
      }
    }
    if (cols % 2 == 1) {
      for (i = start_y; i <= rows - offset; i++) {
        res.push_back(matrix[i][start_y]);
      }
    }

    return res;
  }

  /* 59. 螺旋矩阵 II */
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int start_x = 0, start_y = 0;
    int count = 1;  // 矩阵中的数值
    int loop = n / 2;
    int offset = 1;  // 每条边遍历的长度 n-offset
    int i, j;
    while (loop--) {
      i = start_x;
      j = start_y;
      for (j = start_y; j < n - offset; j++) {
        res[start_x][j] = count++;
      }
      for (i = start_x; i < n - offset; i++) {
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
      offset++;
    }
    if (n % 2 == 1) {
      res[n / 2][n / 2] = count;
    }
    return res;
  }
};

int main() {
  Solution s;

  // 54
  vector<vector<int>> matrix(1, vector<int>(2, 0));
  matrix[0] = {1, 3};
  //   matrix[1] = {4};
  vector<int> result = s.spiralOrder(matrix);

  for (auto x : result) {
    cout << x << '\t';
  }

  // 59
  //   auto res = s.generateMatrix(5);
  //   for (size_t i = 0; i < res.size(); i++) {
  //     for (size_t j = 0; j < res[i].size(); j++) {
  //       cout << res[i][j] << '\t';
  //     }
  //     cout << '\n';
  //   }
  //   system("pause");
  return 0;
}
