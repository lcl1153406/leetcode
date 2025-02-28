/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

 #include <vector>

 using namespace std;

// @lc code=start
class Solution {
public:

    vector<vector<int>> Result;
    vector<int> Path;
    vector<bool> Used;
    vector<vector<int>> permute(vector<int>& nums) {
        Used.resize(nums.size(), false);
        BackTracking(nums);
        return Result;
    }

    void BackTracking(const vector<int>& nums)
    {
        if (Path.size() == nums.size())
        {
            Result.push_back(Path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (Used[i])
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

