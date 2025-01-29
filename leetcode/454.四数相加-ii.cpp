/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> Map1;
        for (auto Val1 : nums1)
        {
            for (auto Val2 : nums2)
            {
                int Sum = Val1 + Val2;
                if (Map1.find(Sum) == Map1.end())
                {
                    Map1[Sum] = 1;
                }
                else
                {
                    Map1[Sum]++;
                }
            }
        }

        int Result = 0;
        for (auto Val1 : nums3)
        {
            for (auto Val2 : nums4)
            {
                int Sum = Val1 + Val2;
                if (Map1.find(-Sum) != Map1.end())
                {
                    Result += Map1[-Sum];
                }
            }
        }
        return Result;
    }
};
// @lc code=end

