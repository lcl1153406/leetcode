/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) > abs(b);
        });

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && k > 0)
            {
                nums[i] *= -1;
                k--;
            }
            if (k == 0)
            {
                break;
            }
        }
        
        if (k % 2 == 1)
        {
            nums.back() *= -1;
        }
        
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end

