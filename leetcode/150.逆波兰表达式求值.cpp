/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

#include <vector>
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> Values;
        for (const auto& Token : tokens)
        {
            if (Token == "+" || Token == "-" || Token == "*" || Token == "/")
            {
                int Value2 = Values.top();
                Values.pop();
                int Value1 = Values.top();
                Values.pop();
                if (Token == "+")
                {
                    Values.push(Value1 + Value2);
                }
                else if (Token == "-")
                {
                    Values.push(Value1 - Value2);
                }
                else if (Token == "*")
                {
                    Values.push(Value1 * Value2);
                }
                else if (Token == "/")
                {
                    Values.push(Value1 / Value2);
                }
            }
            
            else
            {
                Values.push(stoi(Token));
            }
        }
        return Values.top();
    }
};
// @lc code=end

