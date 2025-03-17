// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem84.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int result = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty())
            {
                int mid = st.top();
                int value = 0;
                if (mid >= 0)
                {
                    value = heights[mid];
                }

                if (heights[i] >= value)
                {
                    break;
                }
                               
                st.pop();
                result = max(result, (i - st.top() - 1) * heights[mid]);
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end

