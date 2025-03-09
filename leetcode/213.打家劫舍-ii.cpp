// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem213.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int result1 = rob_impl(nums, 0, nums.size() - 2);
        int result2 = rob_impl(nums, 1, nums.size() - 1);
        return max(result1, result2);
    }

    int rob_impl(vector<int>& nums, int start, int end) {
        if (start > end)
        {
            return 0;
        }
        if (start == end)
        {
            return nums[start];
        }
        int n = end - start + 1;
        vector<int> dp(n, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + start]);
        }
        return dp[n - 1];
    }
};
// @lc code=end

