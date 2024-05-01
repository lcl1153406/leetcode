// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::vector<int> result;
        std::unordered_map<int,int> map;
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (map.count(temp) == 0)
            {
                map.insert({nums[i], i});
            }
            else
            {
                result.push_back(i);
                result.push_back(map[temp]);
                break;
            }
        }
        return result;
    }
};
// @lc code=end

