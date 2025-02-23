// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };

    vector<string> Result;
    string StrRes;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
        {
            return Result;
        }
        
        backTracking(digits, 0);
        return Result;
    }

    void backTracking(const string& digits, int StartIndex) {
        if (StrRes.size() == digits.size())
        {
            Result.push_back(StrRes);
            return;
        }
        
        int Num = digits[StartIndex] - '0';
        string letter = letterMap[Num];
        for (int j = 0; j < letter.size(); j++)
        {
            StrRes.push_back(letter[j]);
            backTracking(digits, StartIndex + 1);
            StrRes.pop_back();
        }
    }
};
// @lc code=end

