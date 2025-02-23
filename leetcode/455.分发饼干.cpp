/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //     sort(g.begin(), g.end());
    //     sort(s.begin(), s.end());

    //     int Result = 0;
    //     int gIndex = g.size() - 1;
    //     int sIndex = s.size() - 1;
    //     while (gIndex >= 0 && sIndex >= 0)
    //     {
    //         if (g[gIndex] <= s[sIndex])
    //         {
    //             Result++;
    //             gIndex--;
    //             sIndex--;
    //         }
    //         else
    //         {
    //             gIndex--;
    //         }
    //     }
    //     return Result;
    // }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int Index = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (Index < g.size() && g[Index] <= s[i])
            {
                Index++;
            }
        }
        return Index;
    }
};
// @lc code=end

