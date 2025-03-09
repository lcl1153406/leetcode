// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem56.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0];
        });      

        vector<vector<int>> Result;
        int Left = intervals[0][0];
        int Right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > Right)
            {
                Result.push_back({Left, Right});
                Left = intervals[i][0];
                Right = intervals[i][1];
            }
            else
            {
                Right = max(Right, intervals[i][1]);
            }   
        }
        Result.push_back({Left, Right});
        return Result;
    }
};
// @lc code=end

