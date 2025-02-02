// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem151.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int Slow = 0;
        int Fast = 0;
        while (Fast < s.size())
        {
            if (s[Fast] != ' ')
            {
                if (Slow != 0)
                {
                    s[Slow++] = ' ';
                }
                while (Fast < s.size() && s[Fast] != ' ')
                {
                    s[Slow++] = s[Fast++];   
                }
            }
            Fast++;
        }

        s.resize(Slow);

        auto Reverse = [&s](int Left, int Right)
        {
            while (Left < Right)
            {
                swap(s[Left], s[Right]);
                Left++;
                Right--;
            }
        };

        Reverse(0, s.size() - 1);
        int Left = 0;
        int Right = 1;
        while (Right <= s.size())
        {
            if (s[Right] == ' '  || Right == s.size())
            {
                Reverse(Left, Right - 1);
                Left = Right + 1;
            }
            Right++;
        }
        return s;
    }
};
// @lc code=end

