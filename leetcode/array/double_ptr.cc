/**
 * \date 2022.9.27
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /* 27. 移除元素 */
  int removeElement(vector<int>& nums, int val) {
    int slow_index = 0;
    for (size_t fast_index = 0; fast_index < nums.size(); ++fast_index) {
      if (nums[fast_index] != val) {
        nums[slow_index++] = nums[fast_index];
      }
    }
    return slow_index;
  }
  int removeElement2(vector<int>& nums, int val) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      for (size_t i = 0; nums[i] != val; ++i) {
        nums[left++] = nums[i];
      }
    }
  }
};

int main() {
  vector<int> v{0, 1, 2, 3, 3, 0, 4, 2};
  Solution s;
  int ret = s.removeElement(v, 2);

  cout << ret << endl;
  return 0;
}
