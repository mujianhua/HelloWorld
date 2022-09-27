/**
 * \date 2022.09.26
 **/

#include <vector>

using namespace std;

class Solution {
 public:
  // 704. 二分查找
  int search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;  // ......
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }

  /* 34. 在排序数组中查找元素的第一个和最后一个位置 */
  vector<int> searchRange(vector<int>& nums, int target) {
    int left_boundary = searchLeftBoundary(nums, target);
    int right_boundary = searchRightBoundary(nums, target);

    if (left_boundary == -2 || right_boundary == -2) return {-1, -1};

    if (right_boundary - left_boundary > 1)
      return {left_boundary + 1, right_boundary - 1};

    return {-1, -1};
  }
  int searchLeftBoundary(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int left_boundary = -2;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] < target) {
        left = middle + 1;
      } else {
        right = middle - 1;
        left_boundary = right;
      }
    }
    return left_boundary;
  }
  int searchRightBoundary(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int right_boundary = -2;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] > target) {
        right = middle - 1;
      } else {
        left = middle + 1;
        right_boundary = left;
      }
    }
    return right_boundary;
  }
  /* 34. 在排序数组中查找元素的第一个和最后一个位置 */

  // 35. 搜索插入位置
  int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] < target)
        left = middle + 1;
      else if (nums[middle] > target)
        right = middle - 1;
      else
        return middle;
    }
    return left;  // .......
  }
};

int main() {
  Solution s;
  return 0;
}
