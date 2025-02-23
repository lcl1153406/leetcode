// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem108.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // 递归写法
    // TreeNode* sortedArrayToBST(vector<int>& nums) {
    //     return sortedArrayToBST_Impl(nums, 0, nums.size() - 1);
    // }

    // TreeNode* sortedArrayToBST_Impl(vector<int>& nums, int StartIndex, int EndIndex) {
    //     if (StartIndex > EndIndex)
    //     {
    //         return nullptr;
    //     }
        
    //     int MidIndex = (EndIndex - StartIndex) / 2 + StartIndex;
    //     TreeNode* Node = new TreeNode{nums[MidIndex]};
    //     Node->left = sortedArrayToBST_Impl(nums, StartIndex, MidIndex - 1);
    //     Node->right = sortedArrayToBST_Impl(nums, MidIndex + 1, EndIndex);
    //     return Node;
    // }

    // 迭代写法
    using FItem = std::tuple<TreeNode*, int, int>;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
        {
            return nullptr;
        }

        TreeNode* Root = new TreeNode{0};
        queue<FItem> Queue;
        Queue.emplace(Root, 0, nums.size() - 1);

        while (!Queue.empty())
        {
            auto [Node, Start, End] = Queue.front();
            Queue.pop();
            int Mid = (End - Start) / 2 + Start;
            Node->val = nums[Mid];

            if (Start <= Mid - 1)
            {
                TreeNode* LeftNode = new TreeNode{0};
                Node->left = LeftNode;
                Queue.emplace(LeftNode, Start, Mid - 1);
            }
            if (Mid + 1 <= End)
            {
                TreeNode* RightNode = new TreeNode{0};
                Node->right = RightNode;
                Queue.emplace(RightNode, Mid + 1, End);
            }
        }
        return Root;
    }
};
// @lc code=end

