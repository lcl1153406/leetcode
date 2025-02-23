//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用 一次 。 
//
// 注意：解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// Related Topics 数组 回溯 👍 1652 👎 0

#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> Result;
    vector<int> Path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        BackTracking(candidates, target,0, 0);
        return Result;
    }

    void BackTracking(vector<int>& candidates, int target, int StartIndex, int Sum) {
        if (Sum == target)
        {
            Result.push_back(Path);
            return;
        }

        for (int i = StartIndex; i < candidates.size(); ++i)
        {
            if (Sum + candidates[i] > target)
            {
                break;
            }
            if (i > StartIndex && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            Path.push_back(candidates[i]);
            BackTracking(candidates, target, i + 1, Sum + candidates[i]);
            Path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
