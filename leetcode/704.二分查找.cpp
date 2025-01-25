// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem704.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /* 左闭有闭
    int search(vector<int>& nums, int target) {
        
        int size = nums.size();
        if(size == 0)
        {
            return -1;
        }
        
        int left = 0;
        int right = size - 1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                return mid;
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

        return -1;
    }
    */
    /* 左闭右开 */
    int search(vector<int>& nums, int target) {
        
        int size = nums.size();
        if(size == 0)
        {
            return -1;
        }
        
        int left = 0;
        int right = size;

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }
    
};
// @lc code=end

