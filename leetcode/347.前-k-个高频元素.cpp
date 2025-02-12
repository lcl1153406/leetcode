/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:

    using FItem = pair<int, int>;

    struct FCompare
    {
        bool operator()(const FItem& Left, const FItem& Right) const
        {
            return Left.second > Right.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> Map;
        for (auto Val : nums)
        {
            if (Map.find(Val) == Map.end())
            {
                Map.insert({Val, 1});
            }
            else
            {
                Map[Val]++;
            }
        }
        
        priority_queue<FItem, vector<FItem>, FCompare> Queue;
        for (const auto& [Val, Count] : Map)
        {
            Queue.push({Val, Count});
            if (Queue.size() > k)
            {
                Queue.pop();
            }
        }

        vector<int> Result;
        Result.reserve(Queue.size());
        while (!Queue.empty())
        {
            Result.push_back(Queue.top().first);
            Queue.pop();
        }
        return Result;
    }
};
// @lc code=end

