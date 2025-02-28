// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem53.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // 动态规划
    // int maxSubArray(vector<int>& nums) {
    //     if (nums.size() == 0)
    //     {
    //         return 0;
    //     }
    //     vector<int> dp(nums.size(), 0);
    //     dp[0] = nums[0];
    //     int Result = dp[0];
    //     for (int i = 1; i < nums.size(); i++)
    //     {
    //         dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    //         Result = max(dp[i], Result);
    //     }
    //     return Result;
    // }

    // 贪心算法
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        int Result = INT_MIN;
        int Sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            Sum += nums[i];
            Result = max(Sum, Result);
            Sum = max(Sum, 0);
        }
        return Result;
    }
};
// @lc code=end

