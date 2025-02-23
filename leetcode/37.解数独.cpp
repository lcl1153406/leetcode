// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem37.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        BackTracking(board);
    }

    // 这个写法有问题，有空还得再研究下
    // bool BackTracking2(int Count, vector<vector<char>>& board)
    // {
    //     if (Count == 9 * 9)
    //     {
    //         return true;
    //     }
    //     int StartRow = Count / 9;
    //     int StartCol = Count % 9;
    //     for (int i = StartRow; i < 9; i++)
    //     {
    //         for (int j = StartCol; j < 9; j++)
    //         {
    //             if (board[i][j] != '.')
    //             {
    //                 continue;
    //             }
                
    //             for (char k = '1'; k <= '9'; k++)
    //             {
    //                 if (!IsValid(i, j, k, board))
    //                 {
    //                     continue;
    //                 }
    //                 board[i][j] = k;
    //                 bool bFlag = BackTracking2(i * 9 + j + 1, board);
    //                 if (bFlag)
    //                 {
    //                     return true;
    //                 }
    //                 board[i][j] = '.';
    //             }
    //             return false;      
    //         }
    //     }
    //     return true;
    // }

    bool BackTracking(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    continue;
                }
                
                for (char k = '1'; k <= '9'; k++)
                {
                    if (!IsValid(i, j, k, board))
                    {
                        continue;
                    }
                    board[i][j] = k;
                    bool bFlag = BackTracking(board);
                    if (bFlag)
                    {
                        return true;
                    }
                    board[i][j] = '.';
                }
                return false;      
            }
        }
        return true;
    }

    bool IsValid(int Row, int Col, char Val, const vector<vector<char>>& board)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[Row][j] == Val)
            {
                return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (board[i][Col] == Val)
            {
                return false;
            }
        }
        
        int StartRow = (Row / 3) * 3;
        int StartCol = (Col / 3) * 3;
        for (int i = StartRow; i < StartRow + 3; i++)
        {
            for (int j = StartCol; j < StartCol + 3; j++)
            {
                if (board[i][j] == Val)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

