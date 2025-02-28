// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem738.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

#include <string>
#include <optional>

using namespace std;

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        optional<int> FindIndex;
        for (int i = s.size() - 1; i > 0; i--)
        {
            if (s[i] < s[i - 1])
            {
                s[i - 1]--;
                FindIndex = i;
            }
        }
        if (FindIndex.has_value())
        {
            for (int i = FindIndex.value(); i < s.size(); i++)
            {
                s[i] = '9';
            }
        }
        return stoi(s);
    }
};
// @lc code=end

