/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <vector>

using namespace std;

// @lc code=start
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         if (nums.empty())
//         {
//             return;
//         }
        
//         int slow = 0;
//         for (size_t fast = 0; fast < nums.size(); fast++)
//         {
//             if (nums[fast] != 0)
//             {
//                 nums[slow] = nums[fast];
//                 slow++;
//             }
//         }

//         for (; slow < nums.size(); slow++)
//         {
//             nums[slow] = 0;
//         }
//     }
// };

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty())
        {
            return;
        }
        
        int slow = 0;
        for (size_t fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0)
            {
                std::swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};
// @lc code=end

