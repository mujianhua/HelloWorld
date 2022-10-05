/**
 * \brief 用来快速判断一个元素是否出现集合里.
 **/
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
  public:
    /********************** 202. 快乐数 *********************/
    bool isHappy(int n)
    {
        unordered_set<int> record_set;
        while (true)
        {
            int sum = GetSum(n);
            if (sum == 1)
            {
                return true;
            }
            if (record_set.find(sum) != record_set.end())
            {
                return false;
            }
            else
            {
                record_set.insert(sum);
            }
            n = sum;
        }
    }
    int GetSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
    /*****************************************************************/

    /*****************************************************************/
    // 349. 两个数组的交集
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> record_set;
        unordered_set<int> ret;
        for (int num : nums1)
        {
            if (record_set.find(num) == record_set.end())
            {
                record_set.insert(num);
            }
        }
        for (int num : nums2)
        {
            // 发现和 record_set 中相同的元素
            if (record_set.find(num) != record_set.end())
            {
                ret.insert(num);
            }
        }
        return vector<int>(ret.begin(), ret.end());
    }
    /*****************************************************************/
};

int main()
{
    Solution s;

    return 0;
}
