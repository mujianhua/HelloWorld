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
    /*****************************************************************/
    bool isAnagram(string s, string t)
    {
        vector<int> record(26, 0);
        for (char c : s)
        {
            record[c - 'a']++;
        }
        for (char c : t)
        {
            record[c - 'a']--;
        }
        for (int i = 0; i < record.size(); i++)
        {
            if (record[i] != 0)
                return false;
        }
        return true;
    }
    /*****************************************************************/

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

    /*****************************************************************/
    // 1. 两数之和
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> record_map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = record_map.find(target - nums[i]);
            if (iter != record_map.end())
            {
                return {iter->second, i};
            }
            record_map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
    /*****************************************************************/

    /*****************************************************************/
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> map; // (a+b, 出现次数)
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                map[a + b]++;
            }
        }
        int count = 0;
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                if (map.find(0 - (c + d)) != map.end())
                {
                    count += map[0 - (c + d)];
                }
            }
        }
        return count;
    }
    /*****************************************************************/
};

int main()
{
    Solution s;

    return 0;
}
