//给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。 
//
// 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [4,6,7,7]
//输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [4,4,3,2,1]
//输出：[[4,4]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 15 
// -100 <= nums[i] <= 100 
// 
//
// Related Topics 位运算 数组 哈希表 回溯 👍 842 👎 0

#include <vector>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> Result;
    vector<int> Path;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        BackTracking(nums, 0);
        return Result;
    }

    void BackTracking(const vector<int>& nums, int StartIndex) {
        if (Path.size() >= 2)
        {
            Result.push_back(Path);
        }
        if (StartIndex >= nums.size())
        {
            return;
        }
        unordered_set<int> UsedSet;
        for (int i = StartIndex; i < nums.size(); ++i)
        {
            if ((Path.size() > 0 && nums[i] < Path.back()) || (UsedSet.find(nums[i]) != UsedSet.end()))
            {
                continue;
            }

            UsedSet.insert(nums[i]);
            Path.push_back(nums[i]);
            BackTracking(nums, i + 1);
            Path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
