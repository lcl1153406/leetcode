// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem494.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

// @lc code=start
class Solution {
public:
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     if (abs(target) > sum)
    //     {
    //         return 0;
    //     }
    //     if ((sum + target) % 2)
    //     {
    //         return 0;
    //     }
        
    //     int value = (sum + target) / 2;
        
    //     vector<int> dp(value + 1, 0);
    //     dp[0] = 1;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         for (int j = value; j >= nums[i]; j--)
    //         {
    //             dp[j] += dp[j - nums[i]]; 
    //         }
    //     }
    //     return dp[value];
    // }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum)
        {
            return 0;
        }
        if ((sum + target) % 2)
        {
            return 0;
        }
        
        int value = (sum + target) / 2;
        
        vector<vector<int>> dp(nums.size(), vector<int>(value + 1, 0));
        if (nums[0] <= value)
        {
            dp[0][nums[0]] = 1;
        }
    
        int zero_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zero_sum++;
            }
            dp[i][0] = pow(2, zero_sum);
        }
        
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 1; j <= value; j++)
            {
                if (j >= nums[i])
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.size()-1][value];
    }
};
// @lc code=end

