/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++)
        {
            for (int j = i * i; j <= n; j++)
            {
                if (dp[j - i * i] != INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }

        if (dp[n] == INT_MAX)
        {
            return 0;
        }
        else
        {
            return dp[n];
        }
    }
};
// @lc code=end

