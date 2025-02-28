//有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 
//和 "192.168@1.1" 是 无效 IP 地址。 
// 
//
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新
//排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
// 
//
// 示例 2： 
//
// 
//输入：s = "0000"
//输出：["0.0.0.0"]
// 
//
// 示例 3： 
//
// 
//输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 20 
// s 仅由数字组成 
// 
//
// Related Topics 字符串 回溯 👍 1483 👎 0

#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
            if (i - StartIndex > 0 && s[StartIndex] == '0')
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
//leetcode submit region end(Prohibit modification and deletion)
