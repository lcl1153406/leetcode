// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem134.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // 暴力解法，时间会超时
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     for (int i = 0; i < gas.size(); i++)
    //     {
    //         int Rest = gas[i] - cost[i];
    //         int Index = (i + 1) % cost.size();
    //         while (Rest > 0 && Index != i)
    //         {
    //             Rest += gas[Index] - cost[Index];
    //             Index = (Index + 1) % cost.size();
    //         }
    //         if (Rest >= 0 && Index == i)
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    // 方法一，不算贪心算法
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int Sum = 0;
    //     int Min = INT_MAX;
    //     for (int i = 0; i < gas.size(); i++)
    //     {
    //         Sum += gas[i] - cost[i];
    //         Min = min(Sum, Min);
    //     }

    //     if (Sum < 0)
    //     {
    //         return -1;
    //     }
        
    //     if (Min >= 0)
    //     {
    //         return 0;
    //     }
        
    //     for (int i = gas.size() - 1; i >= 0; i--)
    //     {
    //         Min += gas[i] - cost[i];
    //         if (Min >= 0)
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    // 贪心算法
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int Sum = 0;
        int CurSum = 0;
        int Start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            Sum += gas[i] - cost[i];
            CurSum += gas[i] - cost[i];
            if (CurSum < 0)
            {
                Start = i + 1;
                CurSum = 0;
            }
        }

        if (Sum >= 0)
        {
            return Start;
        }
    
        return -1;
    }
};
// @lc code=end

