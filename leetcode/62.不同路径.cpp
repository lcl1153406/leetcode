/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, 0));

    //     for (int j = 0; j < n; j++)
    //     {
    //         dp[0][j] = 1;
    //     }
    //     for (int i = 0; i < m; i++)
    //     {
    //         dp[i][0] = 1;
    //     }

    //     for (int i = 1; i < m; i++)
    //     {
    //         for (int j = 1; j < n; j++)
    //         {
    //             dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    //         }
    //     }
    //     return dp[m - 1][n - 1];
    // }

    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

