// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem239.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include <vector>
#include <deque>
#include <set>

using namespace std;

// @lc code=start
class Solution {

// 单调队列的实现方案
/*
    class MyQueue
    {
    public:
        void Push(int Val)
        {
            while (!Deque.empty() && Deque.back() < Val)
            {
                Deque.pop_back();
            }

            Deque.push_back(Val);
        }

        void Pop(int Val)
        {
            if (!Deque.empty() && Deque.front() == Val)
            {
                Deque.pop_front();
            }
        }

        int Front()
        {
            return Deque.front();
        }

    private:
        deque<int> Deque;
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> Result;
        MyQueue Queue;
        for (int i = 0; i < k; i++)
        {
            Queue.Push(nums[i]);
        }
        
        Result.push_back(Queue.Front());
        for (int i = k; i < nums.size(); i++)
        {
            Queue.Pop(nums[i - k]);
            Queue.Push(nums[i]);
            Result.push_back(Queue.Front());
        }
        return Result;
    }
*/

// 对于C++，可以使用multiset来解决
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> Result;
        multiset<int> Set;
        for (int i = 0; i < k; i++)
        {
            Set.insert(nums[i]);
        }
        
        Result.push_back(*Set.rbegin());
        for (int i = k; i < nums.size(); i++)
        {
            Set.erase(Set.find(nums[i - k]));
            Set.insert(nums[i]);
            Result.push_back(*Set.rbegin());
        }
        return Result;
    }
};
// @lc code=end

