// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem435.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

 #include <algorithm>

// @lc code=start
class Solution {
public:
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1)
    {
        return 0;
    }

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    });

    int Count = 1;
    int CurMinEnd = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i][0] >= intervals[i - 1][1])
        {
            CurMinEnd = intervals[i][1];
            Count++;
        }
    }
    return intervals.size() - Count;
}
};
// @lc code=end

