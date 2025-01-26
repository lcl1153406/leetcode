// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem59.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> Result(n, vector<int>(n, 0));    
        int StartI = 0;
        int StartJ = 0;
        int Count = 1;
        int Mid = n / 2;
        int Offset = 1;
        for (int k = 0; k < Mid; k++)
        {
            int i = StartI;
            int j = StartJ;
            for (; j < n - Offset; j++)
            {
                Result[i][j] = Count++;
            }
            for (; i < n - Offset; i++)
            {
                Result[i][j] = Count++;
            }
            for (; j > Offset - 1; j--)
            {
                Result[i][j] = Count++;
            }
            for (; i > Offset - 1; i--)
            {
                Result[i][j] = Count++;
            }
            
            StartI++;
            StartJ++;
            Offset++;
        }
        if (n % 2)
        {
            Result[Mid][Mid] = n * n;
        }
        return Result;
    }
};
// @lc code=end

