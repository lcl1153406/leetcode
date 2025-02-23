/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> Result;
    vector<int> Path;
    vector<bool> Used;
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     Used.resize(nums.size(), false);
    //     BackTracking(nums);
    //     return Result;
    // }

    // void BackTracking(const vector<int>& nums)
    // {
    //     if (nums.size() == Path.size())
    //     {
    //         Result.push_back(Path);
    //     }
    //     unordered_set<int> Set;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (Set.find(nums[i]) != Set.end() || Used[i])
    //         {
    //             continue;
    //         }
    //         Used[i] = true;
    //         Set.insert(nums[i]);
    //         Path.push_back(nums[i]);
    //         BackTracking(nums);
    //         Path.pop_back();
    //         Used[i] = false;
    //     }
    // }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        Used.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        BackTracking(nums);
        return Result;
    }
    
    void BackTracking(const vector<int>& nums)
    {
        if (nums.size() == Path.size())
        {
            Result.push_back(Path);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if ((i > 0 && nums[i] == nums[i - 1] && !Used[i - 1]) || Used[i])
            {
                continue;
            }
            Used[i] = true;
            Path.push_back(nums[i]);
            BackTracking(nums);
            Path.pop_back();
            Used[i] = false;
        }
    }
};
// @lc code=end

