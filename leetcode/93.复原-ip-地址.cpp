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
#include <cmath>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
vector<string> Result;
    vector<string> IPArr;
    vector<string> restoreIpAddresses(string s) {
        BackTracking(s, 0);
        return Result;
    }

    void BackTracking(const string& s, int StartIndex) {
        if (IPArr.size() > 4)
        {
            return;
        }
        if (StartIndex >= s.size() && IPArr.size() == 4)
        {
            string IPStr;
            for (int i = 0; i < IPArr.size(); ++i)
            {
                if (i == 0)
                {
                    IPStr += IPArr[i];
                }
                else
                {
                    IPStr += ".";
                    IPStr += IPArr[i];
                }
            }
            Result.push_back(IPStr);
            return;
        }
        for (int i = StartIndex; i < s.size(); ++i)
        {
            if (i - StartIndex > 2 || ConvertToNumber(s, StartIndex, i) > 255)
            {
                break;
            }
            if (i - StartIndex > 0 && s[i] == '0')
            {
                continue;
            }
            IPArr.push_back(s.substr(StartIndex, i - StartIndex + 1));
            BackTracking(s, i + 1);
            IPArr.pop_back();
        }
    }
    
    int ConvertToNumber(const string& s, int Start, int End)
    {
        if (End < Start)
        {
            return 0;
        }
        int Value = 0;
        while (End >= Start)
        {
            Value += (s[Start] - '0') * std::pow(10, End - Start);
            Start++;
        }
        //std::cout << Value << "\n";
        return Value;
    }
};
// @lc code=end

