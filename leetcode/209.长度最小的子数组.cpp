// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem209.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int Result = INT32_MAX;
        int Sum = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            Sum += nums[j];
            while (Sum >= target)
            {
                int Dis = j - i + 1;
                Result = Result < Dis ? Result : Dis;
                Sum -= nums[i];
                i++;
            }
        }
        return Result == INT32_MAX ? 0 : Result;
    }
};
// @lc code=end

