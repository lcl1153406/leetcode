/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> Result;
    vector<int> Path;
    vector<vector<int>> subsets(vector<int>& nums) {
        BackTracking(nums, 0);
        return Result;
    }

    void BackTracking(const vector<int>& nums, int StartIndex)
    {
        Result.push_back(Path);
        if (StartIndex >= nums.size())
        {
            return;
        }
        for (int i = StartIndex; i < nums.size(); i++)
        {
            Path.push_back(nums[i]);
            BackTracking(nums, i + 1);
            Path.pop_back();
        }
    }
};
// @lc code=end

