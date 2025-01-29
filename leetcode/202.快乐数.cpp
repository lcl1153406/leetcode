// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem202.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> Set;
        while (Set.find(n) == Set.end())
        {
            Set.insert(n);

            int Temp = 0;
            int Val = n;
            while (Val)
            {
                int Mod = Val % 10;
                Temp += Mod * Mod;
                Val = Val / 10;
            }
                  
            if (Temp == 1)
            {
                return true;
            }
            else
            {
                n = Temp;     
            }
        }
        return false;
    }
};
// @lc code=end

