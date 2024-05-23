// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem35.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0)
        {
            return 0;
        }

        int left = 0;
        int right = size - 1;

        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};
// @lc code=end

