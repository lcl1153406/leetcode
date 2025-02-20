// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem93.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

 #include <vector>
 #include <string>

using namespace std;

// @lc code=start
class Solution {
public:

    vector<string> Result;
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return Result;
        BackTracking(s, 0, 0);
        return Result;
    }

    void BackTracking(string s, int StartIndex, int PointNum) {
        if (PointNum == 3)
        {
            if (IsValidStr(s, StartIndex, s.size() - 1))
            {
                Result.push_back(s);
            }
            return;
        }
        
        for (int i = StartIndex; i < s.size(); i++)
        {
            if (!IsValidStr(s, StartIndex, i))
            {
                break;
            }
            s.insert(s.begin() + i + 1, '.');
            BackTracking(s, i + 2, PointNum + 1);
            s.erase(s.begin() + i + 1);
        }
    }

    bool IsValidStr(const string& s, int Start, int End){
        if (Start > End)
        {
            return false;
        }
        
        if (End - Start > 0 && s[Start] == '0')
        {
            return false;
        }
        
        int Num = 0;
        for (int i = Start; i <= End; i++)
        {
            if (s[i] > '9' || s[i] < '0')
            {
                return false;
            }
            Num = Num * 10 + s[i] - '0';
            if (Num > 255)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

