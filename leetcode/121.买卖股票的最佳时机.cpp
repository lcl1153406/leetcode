/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2, 0));
    //     dp[0][0] = -prices[0];
    //     dp[0][1] = 0;

    //     for (int i = 1; i < n; i++)
    //     {
    //         dp[i][0] = max(dp[i - 1][0], -prices[i]);
    //         dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    //     }

    //     return dp[n - 1][1];
    // }

    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //      vector<int> dp(2, 0);
    //     dp[0] = -prices[0];
    //     dp[1] = 0;

    //     for (int i = 1; i < n; i++)
    //     {
    //         int temp1 = max(dp[0], -prices[i]);
    //         int temp2 = max(dp[1], dp[0] + prices[i]);
    //         dp[0] = temp1;
    //         dp[1] = temp2;
    //     }

    //     return dp[1];
    // }

    int maxProfit(vector<int>& prices) {
        int result = 0;
        int min_value = INT_MAX;

        for (int i = 0; i < prices.size(); i++)
        {
            min_value = min(min_value, prices[i]);
            result = max(result, prices[i] - min_value);
        }

        return result;
    }
};
// @lc code=end

