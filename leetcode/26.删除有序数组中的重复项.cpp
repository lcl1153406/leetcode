/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.empty())
        {
            return 0;
        }
        
        int slow = 1;
        for (int fast = 1; fast < nums.size(); fast++)
        {
            if (nums[fast] != nums[slow - 1])
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
// @lc code=end

