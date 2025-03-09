/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                int Temp = max(j*(i - j), j*dp[i - j]);
                dp[i] = max(dp[i], Temp);
            }
        }
        return dp[n];
    }
};
// @lc code=end

