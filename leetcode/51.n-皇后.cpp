// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem51.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:

    vector<vector<string>> Result;
    vector<string> Path;
    vector<vector<string>> solveNQueens(int n) {
        Path.resize(n, string(n, '.'));
        BackTracking(n, 0);
        return Result;
    }

    void BackTracking(int n, int RowIndex)
    {
        if (RowIndex == n)
        {
            Result.push_back(Path);
            return;
        }
        
        for (int ColIndex = 0; ColIndex < n; ColIndex++)
        {
            if (!IsValid(n, RowIndex, ColIndex))
            {
                continue;
            }
            Path[RowIndex][ColIndex] = 'Q';
            BackTracking(n, RowIndex + 1);
            Path[RowIndex][ColIndex] = '.';
        }
        
    }

    bool IsValid(int n, int RowIndex, int ColIndex)
    {
        for (int i = 0; i < RowIndex; i++)
        {
            if (Path[i][ColIndex] == 'Q')
            {
                return false;
            }
        }
        for (int i = RowIndex - 1, j = ColIndex - 1; i >= 0 && j>= 0; i--, j--)
        {
            if (Path[i][j] == 'Q')
            {
                return false;
            }
        }
        for (int i = RowIndex - 1, j = ColIndex + 1; i >= 0 && j < n; i--, j++)
        {
            if (Path[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

