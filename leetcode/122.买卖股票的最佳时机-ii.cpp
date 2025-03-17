/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int result = 0;
    //     for (int i = 0; i < prices.size() - 1; i++)
    //     {
    //         if (prices[i + 1] > prices[i])
    //         {
    //             result += prices[i + 1] - prices[i];
    //         }
    //     }
    //     return result;
    // }

    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2, 0));
    //     dp[0][0] = -prices[0];
    //     dp[0][1] = 0;
    //     for (int i = 1; i < n; i++)
    //     {
    //         dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
    //         dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    //     }
    //     return dp[n - 1][1];
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2, 0);
        dp[0] = -prices[0];
        dp[1] = 0;
        for (int i = 1; i < n; i++)
        {
            int temp1 = max(dp[0], dp[1] - prices[i]);
            int temp2 = max(dp[1], dp[0] + prices[i]);
            dp[0] = temp1;
            dp[1] = temp2;
        }
        return dp[1];
    }
};
// @lc code=end

