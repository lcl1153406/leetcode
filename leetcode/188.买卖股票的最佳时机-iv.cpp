/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for (int j = 1; j < k + 1; j++)
        {
            dp[0][j][0] = -prices[0];
        }
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < k + 1; j++)
            {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] - prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] + prices[i]);
            }
        }
        return dp[n - 1][k][1];
    }
};
// @lc code=end

