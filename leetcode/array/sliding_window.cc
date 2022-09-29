#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /* 209. 长度最小的子数组 */
  int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    int sub_length = 0;
    int i = 0;
    int result = INT32_MAX;
    for (int j = 0; j < nums.size(); j++) {
      sum += nums[j];
      while (sum >= target) {
        sub_length = j - i + 1;
        result = result < sub_length ? result : sub_length;
        sum -= nums[i++];
      }
    }
    return result == INT32_MAX ? 0 : result;
  }
};

int main() {
  vector<int> test{5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
  Solution s;

  int ret = s.minSubArrayLen(15, test);
  cout << ret << endl;
  return 0;
}
