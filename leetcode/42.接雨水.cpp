// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem42.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // int trap(vector<int>& height) {
    //     int n = height.size();
        
    //     vector<int> pre_max(n);
    //     pre_max[0] = height[0];
    //     for (int i = 1; i < n; i++)
    //     {
    //         pre_max[i] = max(pre_max[i-1], height[i]); 
    //     }
        
    //     vector<int> suff_max(n);
    //     suff_max[n-1] = height[n-1];
    //     for (int i = n-2; i >= 0; i--)
    //     {
    //         suff_max[i] = max(suff_max[i+1], height[i]);
    //     }
        
    //     int result = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         result += (min(pre_max[i], suff_max[i]) - height[i]);
    //     }
        
    //     return result;
    // }

    int trap(vector<int>& height) {
        int n = height.size();
        
        int pre_max = 0;
        int suff_max = 0;
        int left = 0;
        int right = n - 1;
        int result = 0;
        while (left <= right)
        {
            pre_max = max(pre_max, height[left]);
            suff_max = max(suff_max, height[right]);
            if (pre_max <= suff_max)
            {
                result += pre_max - height[left];
                left++;
            }
            else
            {
                result += suff_max - height[right];
                right--;
            }
        }
        
        return result;
    }
};
// @lc code=end

