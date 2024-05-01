/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxPos = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxPos) {
                return false;
            }
            maxPos = max(maxPos, i + nums[i]);
            if (maxPos >= n - 1) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

