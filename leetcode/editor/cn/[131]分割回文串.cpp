//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：[["a"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 16 
// s 仅由小写英文字母组成 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 1936 👎 0

#include <string>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    
    // 实时判断每个子串是否为回文字符串
    // vector<vector<string>> Result;
    // vector<string> Path;
    // vector<vector<string>> partition(string s) {
    //     BackTracking(s, 0);
    //     return Result;
    // }
    //
    // void BackTracking(string s, int StartIndex) {
    //     if (StartIndex >= s.size())
    //     {
    //         Result.push_back(Path);
    //         return;
    //     }
    //     for (int i = StartIndex; i < s.size(); ++i)
    //     {
    //         string subStr = s.substr(StartIndex, i - StartIndex + 1);
    //         if (!IsValid(subStr))
    //         {
    //             continue;
    //         }
    //         Path.push_back(subStr);
    //         BackTracking(s, i + 1);
    //         Path.pop_back();
    //     }
    // }
    //
    // bool IsValid(string s)
    // {
    //     int Left = 0;
    //     int Right = s.size()- 1;
    //     while (Left <= Right)
    //     {
    //         if (s[Left] != s[Right])
    //         {
    //             return false;
    //         }
    //         Left++;
    //         Right--;
    //     }
    //     return true;
    // }

    // 预先缓存每个子串是否为回温字符串
    vector<vector<string>> Result;
    vector<string> Path;
    vector<vector<bool>> ValidArr;
    vector<vector<string>> partition(string s) {
        CacheSubStrValid(s);
        BackTracking(s, 0);
        return Result;
    }

    void BackTracking(string s, int StartIndex) {
        if (StartIndex >= s.size())
        {
            Result.push_back(Path);
            return;
        }
        for (int i = StartIndex; i < s.size(); ++i)
        {
            if (!ValidArr[StartIndex][i])
            {
                continue;
            }
            string subStr = s.substr(StartIndex, i - StartIndex + 1);
            Path.push_back(subStr);
            BackTracking(s, i + 1);
            Path.pop_back();
        }
    }
    // 动态规划
    void CacheSubStrValid(string s)
    {
        ValidArr.resize(s.size(), vector<bool>(s.size(), false));
        for (int j = 0; j < s.size(); ++j)
        {
            for (int i = 0; i <= j; ++i)
            {
                if (i == j)
                {
                    ValidArr[i][j] = true;
                }
                else if(j - i == 1)
                {
                    ValidArr[i][j] = s[i] == s[j];
                }
                else
                {
                    ValidArr[i][j] = ValidArr[i + 1][j - 1] && s[i] == s[j];
                }
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
