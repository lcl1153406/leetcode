/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> Result;
    vector<int> Path;
    vector<vector<int>> combinationSum3(int k, int n) {
        combinationSum3_Impl(k, n, 1, 0);
        return Result;
    }

    void combinationSum3_Impl(int k, int n, int Start, int Sum) {
        if (Sum > n)
        {
            return;
        }
        
        if (Path.size() == k)
        {
            if (Sum == n)
            {           
                Result.push_back(Path);
            }
            return;
        }
        for (int i = Start; i <= (9 - (k - Path.size()) + 1); i++)
        {
            Path.push_back(i);
            combinationSum3_Impl(k, n, i+1, Sum + i);
            Path.pop_back();
        }
    }
};
// @lc code=end

