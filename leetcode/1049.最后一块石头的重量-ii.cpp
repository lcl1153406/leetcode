/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int part_sum = sum / 2;
        int n = stones.size();

        vector<int> dp(part_sum + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = part_sum; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
            }
        }
        return abs(sum - 2*dp[part_sum]); 
    }
};
// @lc code=end

