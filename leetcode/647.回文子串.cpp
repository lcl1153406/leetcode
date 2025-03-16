/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // int countSubstrings(string s) {
    //     int n = s.size();
    //     vector<int> dp(n, 0);
    //     dp[0] = 1;
    //     for (int i = 1; i < n; i++)
    //     {
    //         dp[i] = dp[i - 1];
    //         for (int j = 0; j <= i; j++)
    //         {
    //             if (IsValidStr(s, j , i))
    //             {
    //                 dp[i]++;
    //             }
    //         }
    //     }
    //     return dp[n - 1];
    // }

    // bool IsValidStr(const string& s, int start, int end)
    // {
    //     while (start <= end)
    //     {
    //         if (s[start] == s[end])
    //         {
    //             start++;
    //             end--;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // int countSubstrings(string s) {
    //     int n = s.size();
    //     vector<vector<bool>> dp(n, vector<bool>(n, false));
    //     int result = 0;
    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         for (int j = i; j < n; j++)
    //         {
    //             if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]))
    //             {
    //                 result++;
    //                 dp[i][j] = true;
    //             }
    //         }
    //     }
    //     return result;
    // }

    int countSubstrings(string s) {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result += GetCount(s, i, i);
            result += GetCount(s, i, i + 1);
        }
        return result;
    }

    int GetCount(const string& s, int i, int j)
    {
        int result = 0;
        int n = s.size();
        while (i >= 0 && j < n)
        {
            if (s[i] == s[j])
            {
                result++;
                i--;
                j++;
            }
            else
            {
                break;
            }
        }
        return result;
    }
};
// @lc code=end

