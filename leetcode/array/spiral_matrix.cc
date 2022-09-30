#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /* 54. 螺旋矩阵 */
  // todo:..................
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> res;
    if (rows == 0 || cols == 0) return res;

    int i, j;
    int left = 0, right = cols - 1;
    int top = 0, bottom = rows - 1;
    while (left <= right && top <= bottom) {
      for (j = left; j <= right; j++) {
        res.push_back(matrix[top][j]);
      }
      for (i = top + 1; i <= bottom; i++) {
        res.push_back(matrix[i][right]);
      }
      if (left < right && top < bottom) {
        for (j = right - 1; j > left; j--) {
          res.push_back(matrix[bottom][j]);
        }
        for (i = bottom; i > top; i--) {
          res.push_back(matrix[i][left]);
        }
      }
      left++;
      top++;
      right--;
      bottom--;
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
