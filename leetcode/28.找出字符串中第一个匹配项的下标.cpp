/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); i++)
        {
            int TempIndex = i;
            bool bMathch = true;
            for (int j = 0; j < needle.size(); j++)
            {
                if (needle[j] == haystack[i])
                {
                    i++;   
                }
                else
                {
                    bMathch = false;
                    i = TempIndex;
                    break;
                }
            }
            if (bMathch)
            {
                return i - needle.size();
            }
        }
        return -1;
    }
};
// @lc code=end

