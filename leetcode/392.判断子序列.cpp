/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // bool isSubsequence(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();
    //     int i = 0;
    //     int j = 0;
    //     while (i < n && j < m)
    //     {
    //         if (s[i] == t[j])
    //         {
    //             i++;
    //             j++;
    //         }
    //         else
    //         {
    //             j++;
    //         }
    //     }
    //     return i == n;
    // }

    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }   
            }
        }
        return dp[n][m] == n;
    }
};
// @lc code=end

