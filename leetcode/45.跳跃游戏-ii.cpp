// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem45.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 0;
        }
        int Result = 0;
        int CurCover = 0;
        int NextCover = 0;
        for (int i = 0; i <= CurCover; i++)
        {
            NextCover = max(nums[i] + i, NextCover);
            if (i == CurCover)
            {
                Result++;
                CurCover = NextCover;
                if (CurCover >= nums.size() - 1)
                {
                    break;
                }
            }
        }
        return Result;
    }
};
// @lc code=end

