/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include <vector>


using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int result = 0;
        while(start != end)
        {
            int temp = min(height[start], height[end]) * (end - start);
            result = max(result, temp);

            if (height[start] <= height[end])
            {
                ++start;
            }
            else
            {
                --end;
            }
        }
        return result;
    }
};
// @lc code=end

