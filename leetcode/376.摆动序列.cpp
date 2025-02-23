/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // 贪心算法
    // int wiggleMaxLength(vector<int>& nums) {
    //     if (nums.size() <= 1)
    //     {
    //         return nums.size();
    //     }
    //     int CurDiff = 0;
    //     int PreDiff = 0;
    //     int Result = 1;
    //     for (int i = 0; i < nums.size() - 1; i++)
    //     {
    //         CurDiff = nums[i + 1] - nums[i];
    //         if ((PreDiff >= 0 && CurDiff < 0)
    //             || (PreDiff <= 0 && CurDiff > 0))
    //         {
    //             Result++;
    //             PreDiff = CurDiff;
    //         }
    //     }
    //     return Result;
    // }

    // 动态规划
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        vector<vector<int>> dp(nums.size(), vector<int>(2, 1));
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
                else if (nums[i] < nums[j])
                {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
        }
        return max(dp.back()[0], dp.back()[1]);
    }
};
// @lc code=end

