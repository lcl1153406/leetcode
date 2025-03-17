/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:

    // 暴力解法--超时
    // vector<int> dailyTemperatures(vector<int>& temperatures) {
    //     vector<int> result(temperatures.size(), 0);
    //     for (int i = 0; i < temperatures.size(); i++)
    //     {
    //         for (int j = i + 1; j < temperatures.size(); j++)
    //         {
    //             if (temperatures[j] > temperatures[i])
    //             {
    //                 result[i] = j - i;
    //                 break;
    //             }
    //         }
    //     }
    //     return result;
    // }


    // vector<int> dailyTemperatures(vector<int>& temperatures) {
    //     vector<int> result(temperatures.size(), 0);
    //     stack<int> st;
    //     for (int i = 0; i < temperatures.size(); i++)
    //     {
    //         while (!st.empty())
    //         {
    //             int index = st.top();
    //             if (temperatures[i] > temperatures[index])
    //             {
    //                 result[index] = i - index;
    //                 st.pop();
    //             }
    //             else
    //             {
    //                 break;
    //             }
    //         }
    //         st.push(i);
    //     }
    //     return result;
    // }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> st;
        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            while (!st.empty())
            {
                int index = st.top();
                if (temperatures[i] >= temperatures[index])
                {
                    st.pop();
                }
                else
                {
                    break;
                }
            }

            if (!st.empty())
            {
                result[i] = st.top() - i;
            }
            
            st.push(i);
        }
        return result;
    }
};
// @lc code=end

