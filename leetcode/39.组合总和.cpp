// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem39.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
    public:
        vector<vector<int>> Result;
        vector<int> Path;
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            BackTracking(candidates, target, 0, 0);
            return Result;
        }
    
        void BackTracking(vector<int>& candidates, int target, int StartIndex, int Sum) {
            if (Sum > target)
            {
                return;
            }
            if (target == Sum)
            {
                Result.push_back(Path);
                return;
            }
    
            for (int i = StartIndex; i < candidates.size(); ++i)
            {
                Path.push_back(candidates[i]);
                BackTracking(candidates, target, StartIndex, Sum + candidates[i]);
                Path.pop_back();
            }
        }
    };
// @lc code=end

