// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem977.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);

        int left = 0;
        int right = size - 1;
        int index = size - 1;

        while (left <= right)
        {
            int left_quart = nums[left] * nums[left];
            int right_quart = nums[right] * nums[right];
            if (left_quart < right_quart)
            {
                result[index] = right_quart;
                right--;
            }
            else
            {
                result[index] = left_quart;
                left++;
            }
            index--;
        }
        return result;
    }
};
// @lc code=end

