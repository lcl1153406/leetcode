/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_map<int, int> map;
    //     for (int i = 0; i < nums1.size(); i++)
    //     {
    //         map.insert({nums1[i], i});
    //     }
    //     vector<int> result(nums1.size(), -1);
    //     stack<int> st;
    //     for (int i = 0; i < nums2.size(); i++)
    //     {
    //         while (!st.empty() && nums2[i] > nums2[st.top()])
    //         {
    //             if (map.find(nums2[st.top()]) != map.end())
    //             {
    //                 result[map[nums2[st.top()]]] = nums2[i];
    //             }
    //             st.pop();
    //         }
    //         st.push(i);
    //     }
    //     return result;
    // }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;   
        stack<int> st;
        for (int i = 0; i < nums2.size(); i++)
        {
            while (!st.empty() && nums2[i] > st.top())
            {
                map.insert({st.top(), nums2[i]});
                st.pop();
            }
            st.push(nums2[i]);
        }

        vector<int> result(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++)
        {
            if (map.find(nums1[i]) != map.end())
            {
                result[i] = map[nums1[i]];
            }
        }

        return result;
    }
};
// @lc code=end

