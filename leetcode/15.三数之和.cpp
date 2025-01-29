// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return {};
        }
        vector<vector<int>> Result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            int Left = i + 1;
            int Right = nums.size() - 1; 
            if (i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
                   
            while (Left < Right)
            {
                int Sum = nums[i] + nums[Left] + nums[Right];
                if (Sum == 0)
                {
                    Result.push_back({nums[i], nums[Left], nums[Right]});
                    while (true)
                    {
                        Left++;
                        if (Left >= Right)
                        {
                            break;
                        }
                        if (nums[Left] != nums[Left-1])
                        {
                            break;
                        }
                    }
                    while (true)
                    {
                        Right--;
                        if (Left >= Right)
                        {
                            break;
                        }
                        if (nums[Right] != nums[Right+1])
                        {
                            break;
                        }
                    }                 
                }
                else if (Sum < 0)
                {
                    Left++;
                }
                else
                {
                    Right--;
                }  
            }
        }
        return Result;
    }
};
// @lc code=end

