/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
 */

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
    TreeNode* bstToGst(TreeNode* root) {
        int LastValue = 0;
        bstToGst_Impl(root, LastValue);
        return root;
    }

    void bstToGst_Impl(TreeNode* root, int& LastValue) {
        if (!root)
        {
            return;
        }
        
        bstToGst_Impl(root->right, LastValue);

        root->val += LastValue;
        LastValue = root->val;

        bstToGst_Impl(root->left, LastValue);
    }
};
// @lc code=end

