/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */

#include <vector>
#include <stack>

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
    int findBottomLeftValue(TreeNode* root) {
        int MaxDepth = 0;
        int Result = 0;
        FindLeftValue(root, 1, MaxDepth, Result);
        return Result;
    }

    void FindLeftValue(TreeNode* Node, int Depth, int& MaxDepth, int& Value)
    {
        if (!Node)
        {
            return;
        }
        if (!Node->left && !Node->right)
        {
            if (Depth > MaxDepth)
            {
                MaxDepth = Depth;
                Value = Node->val;
            }
            return;
        }
        if (Node->left)
        {
            FindLeftValue(Node->left, Depth + 1, MaxDepth, Value);
        }
        if (Node->right)
        {
            FindLeftValue(Node->right, Depth + 1, MaxDepth, Value);
        }
    }
};
// @lc code=end

