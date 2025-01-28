// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem349.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

#include <vector>
#include <unordered_set>
#include <array>

using namespace std;

// @lc code=start
class Solution {
public:
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_set<int> Set;
    //     for(auto Value : nums1)
    //     {
    //         Set.insert(Value);
    //     }
    //     vector<int> Result;
    //     for(auto Value : nums2)
    //     {
    //         if (Set.find(Value) != Set.end())
    //         {
    //             Result.push_back(Value);
    //             Set.erase(Value);
    //         }
    //     }
    //     return Result;
    // }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        array<int, 1001> Arr{};
        for(auto Value : nums1)
        {
            Arr[Value] = 1;
        }
        vector<int> Result;
        for(auto Value : nums2)
        {
            if (Arr[Value] == 1)
            {
                Result.push_back(Value);
                Arr[Value] = 0;
            }
        }
        return Result;
    }
};
// @lc code=end

