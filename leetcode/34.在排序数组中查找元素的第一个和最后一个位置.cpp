/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0)
        {
            return {-1, -1};
        }

        int left = 0;
        int right = size - 1;

        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
            {
                left = mid;
                right = mid;
                while (left >= 0 && nums[left] == target)
                {
                    left--;
                }
                while (right < size && nums[right] == target)
                {
                    right++;
                }

                return {left+1, right-1};            
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return {-1, -1};
    }
};
// @lc code=end

