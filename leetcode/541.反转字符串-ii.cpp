// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem541.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    // string reverseStr(string s, int k) {
    //     int Size = s.size();
    //     int Count = Size / (2 * k);
    //     int Mod = Size % (2 * k);

    //     auto Reverse = [&s](int Left, int Right)
    //     {
    //         while (Left < Right)
    //         {
    //             swap(s[Left], s[Right]);
    //             Left++;
    //             Right--;
    //         }
    //     };

    //     for (int i = 0; i < Count; i++)
    //     {
    //         int Left = i * 2 * k;
    //         int Right = i * 2 * k + k - 1;
    //         Reverse(Left, Right);
    //     }
    //     if (Mod < k)
    //     {
    //         int Left = Count * 2 * k;
    //         int Right = Size - 1;
    //         Reverse(Left, Right);
    //     }
    //     else if (Mod >= k)
    //     {
    //         int Left = Count * 2 * k;
    //         int Right = Count * 2 * k + k - 1;
    //         Reverse(Left, Right);
    //     }
    //     return s;
    // }

    // string reverseStr(string s, int k) {
    //     for (int i = 0; i < s.size(); i += 2*k)
    //     {
    //         if (i + k <= s.size())
    //         {
    //             reverse(s.begin() + i, s.begin() + i + k);
    //         }
    //         else
    //         {
    //             reverse(s.begin() + i, s.end());
    //         }
    //     }
    //     return s;
    // }

    string reverseStr(string s, int k) {
        auto Reverse = [&s](int Left, int Right)
        {
            while (Left < Right)
            {
                swap(s[Left], s[Right]);
                Left++;
                Right--;
            }
        };
        for (int i = 0; i < s.size(); i += 2*k)
        {
            if (i + k <= s.size())
            {
                Reverse(i, i + k - 1);
            }
            else
            {
                Reverse(i, s.size() - 1);
            }
        }
        return s;
    }
};
// @lc code=end

