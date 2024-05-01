/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        std::priority_queue<int, vector<int>, greater<>> heap;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (heap.size() < k)
            {
                heap.push(nums[i]);
            }
            else
            {
                if (nums[i] > heap.top())
                {
                    heap.pop();
                    heap.push(nums[i]);
                }
            }
        }
        return heap.top();
    }
};
// @lc code=end

