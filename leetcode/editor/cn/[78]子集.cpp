//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// nums 中的所有元素 互不相同 
// 
//
// Related Topics 位运算 数组 回溯 👍 2434 👎 0

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> Result;
    vector<int> SubSet;
    vector<vector<int>> subsets(vector<int>& nums) {
        BackTracking(nums, 0);
        return Result;
    }

    void BackTracking(const vector<int>& nums, int StartIndex)
    {
        if (StartIndex >= nums.size())
        {
            Result.push_back(SubSet);
            return;
        }

        int Value = nums[StartIndex];
        for (int i = 0; i < 2; ++i)
        {
            if (i == 1)
            {
                SubSet.push_back(Value);
            }
            BackTracking(nums, StartIndex + 1);
            if (i == 1)
            {
                SubSet.pop_back();
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
