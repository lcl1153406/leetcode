// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem844.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

#include <string>

using namespace std;

// @lc code=start
// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         int num1 = GetNewString(s);
//         int num2 = GetNewString(t);
//         if (num1 != num2)
//         {
//             return false;
//         }
        
//         bool result = true;
//         for (size_t i = 0; i < num1; i++)
//         {
//             if (s[i] != t[i])
//             {
//                 result = false;
//                 break;
//             }
//         }
//         return result;
//     }

//     int GetNewString(string& Origin)
//     {
//         int slow = 0;
//         for (size_t fast = 0; fast < Origin.size(); fast++)
//         {
//             if (Origin[fast] != '#')
//             {
//                 Origin[slow] = Origin[fast];
//                 slow++;
//             }
//             else
//             {
//                 if (slow > 0)
//                 {                                  
//                     slow--;
//                 }
//             }
//         }
//         return slow;
//     }
// };


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int skip_i = 0;
        int skip_j = 0;

        while (i >= 0 || j >= 0)
        {
            while (i >= 0)
            {
                if (s[i] == '#')
                {
                    skip_i++;
                    i--;
                }
                else if (skip_i > 0)
                {
                    skip_i--;
                    i--;
                }
                else
                {
                    break;
                }
            }
            
            while (j >= 0)
            {
                if (t[j] == '#')
                {
                    skip_j++;
                    j--;
                }
                else if (skip_j > 0)
                {
                    skip_j--;
                    j--;
                }
                else
                {
                    break;
                }
            }

            if (i >= 0 && j >= 0)
            {
                if (s[i] != t[j])
                {
                    return false;
                }
            }
            else
            {
                if (i >= 0 || j >= 0)
                {
                    return false;
                }
            }

            i--;
            j--;
        }
        return true;
    }
};
// @lc code=end

