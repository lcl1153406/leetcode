/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:

    vector<vector<int>> Result;
    vector<int> Path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
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
            if (i > StartIndex && nums[i] == nums[i - 1])
            {
                continue;;
            }
            Path.push_back(nums[i]);
            BackTracking(nums, i + 1);
            Path.pop_back();
        }
    }
};
// @lc code=end

