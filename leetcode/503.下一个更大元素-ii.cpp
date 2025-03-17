// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem503.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        for (int i = 0; i < n * 2; i++)
        {
            while (!st.empty() && nums[i % n] > nums[st.top()])
            {
                result[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return result;
    }
};
// @lc code=end

