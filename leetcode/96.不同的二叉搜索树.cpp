// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem96.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];  
            }
        }
        return dp[n];
    }
};
// @lc code=end

