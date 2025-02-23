/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> Result;
    vector<int> Path;
    vector<vector<int>> combine(int n, int k) {
        
        combine_Impl(n, k, 1);
        return Result;
    }

    void combine_Impl(int n, int k, int Start) {
        if (Path.size() == k)
        {
            Result.push_back(Path);
            return;
        }
        for (int i = Start; i <= (n - (k - Path.size()) + 1); i++)
        {
            Path.push_back(i);
            combine_Impl(n, k, i + 1);
            Path.pop_back();
        }
    }
};
// @lc code=end

