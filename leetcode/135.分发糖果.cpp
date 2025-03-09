// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem135.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> CandyArr(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                CandyArr[i] = CandyArr[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                CandyArr[i] = max(CandyArr[i], CandyArr[i + 1] + 1);
            }
        }
        
        return accumulate(CandyArr.begin(), CandyArr.end(), 0);
    }
};
// @lc code=end

