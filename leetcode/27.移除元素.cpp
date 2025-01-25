// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem27.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <vector>

using namespace std;

// @lc code=start
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int slow = 0;
//         for (int fast = 0; fast < nums.size(); fast++)
//         {
//             if (nums[fast] != val)
//             {
//                 nums[slow] = nums[fast];
//                 slow++;
//             }
//         }
//         return slow;
//     }
// };

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            if (nums[left] == val)
            {
                if (nums[right] != val)
                {
                    nums[left] = nums[right];
                }
                right--;
            }
            else
            {
                left++;
            }
        }
        return left;
    }
};
// @lc code=end

