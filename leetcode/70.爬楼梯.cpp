/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <vector>
#include <array>

using namespace std;

// @lc code=start
class Solution {
public:
    // int climbStairs(int n) {
    //     if (n <= 2)
    //     {
    //         return n;
    //     }
        
    //     vector<int> dp(n + 1, 0);
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for (int i = 3; i <= n; i++)
    //     {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }

    int climbStairs(int n) {
        if (n <= 2)
        {
            return n;
        }
        
        array<int, 2> dp{};
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 3; i <= n; i++)
        {
            int Temp = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = Temp;
        }
        return dp[1];
    }
};
// @lc code=end

