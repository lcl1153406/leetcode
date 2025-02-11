/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

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

    // 递归写的--前序遍历
    // int sumOfLeftLeaves(TreeNode* root) {
    //     int Sum = 0;
    //     GetSumLeftLeaves(root, Sum);
    //     return Sum;
    // }

    // void GetSumLeftLeaves(TreeNode* Node, int& Sum)
    // {
    //     if (!Node)
    //     {
    //         return;
    //     }
    //     if (Node->left && !Node->left->left && !Node->left->right)
    //     {
    //         Sum += Node->left->val;
    //     }
    //     GetSumLeftLeaves(Node->left, Sum);
    //     GetSumLeftLeaves(Node->right, Sum);
    // }

    // 递归写的--后序遍历
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
        {
            return 0;
        }

        if (!root->left && !root->right)
        {
            return 0;
        }

        int SumLeft = sumOfLeftLeaves(root->left);
        int SumRight = sumOfLeftLeaves(root->right);
        int SumMid = 0;
        if (root->left && !root->left->left && !root->left->right)
        {
            SumMid = root->left->val;
        }

        return SumMid + SumLeft + SumRight;
    }
};
// @lc code=end

