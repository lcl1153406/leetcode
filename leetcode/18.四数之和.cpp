// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem18.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
        {
            return {};
        }
        vector<vector<int>> Result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
        {          
            if (nums[i] > target && nums[i] >= 0)
            {
                break;
            }
              
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if ((nums[i] + nums[j] > target) && (nums[i] + nums[j] >= 0))
                {
                    break;
                }
                
                if ((j - i > 1) && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int Left = j + 1;
                int Right = nums.size() - 1;
                while (Left < Right)
                {
                    long long int Sum = static_cast<long long int>(nums[i]) + nums[j] + nums[Left] + nums[Right];
                    if (Sum > target)
                    {
                        Right--;
                    }
                    else if(Sum < target)
                    {
                        Left++;
                    }
                    else
                    {
                        Result.push_back({nums[i], nums[j], nums[Left], nums[Right]});
                        while (true)
                        {
                            Left++;
                            if (Left >= Right)
                            {
                                break;
                            }
                            if (nums[Left] != nums[Left - 1])
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
                            if (nums[Right] != nums[Right + 1])
                            {
                                break;
                            }
                        }                 
                    }
                }
                
            } 
        }
        return Result;
    }
};
// @lc code=end

