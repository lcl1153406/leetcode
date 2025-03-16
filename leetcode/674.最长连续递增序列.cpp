/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // int findLengthOfLCIS(vector<int>& nums) {
    //     int result = 1;
    //     int count = 1;
    //     for (int i = 1; i < nums.size(); i++)
    //     {
    //         if (nums[i] > nums[i - 1])
    //         {
    //             count++;
    //             result = max(result, count);
    //         }
    //         else
    //         {
    //             count = 1;
    //         }
    //     }
    //     return result;
    // }

    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int result = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            result = max(dp[i], result);
        }
        return result;
    }
};
// @lc code=end

