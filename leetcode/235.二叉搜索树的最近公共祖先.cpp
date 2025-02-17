/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // 递归写法
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (!root)
    //     {
    //         return nullptr;
    //     }
        
    //     if (root->val > p->val && root->val > q->val)
    //     {
    //         return lowestCommonAncestor(root->left, p, q);
    //     }
    //     if(root->val < p->val && root->val < q->val)
    //     {
    //         return lowestCommonAncestor(root->right, p, q);
    //     }
    //     return root;
    // }

    // 迭代写法
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* Node = root;
        while (Node)
        {
            if (Node->val > p->val && Node->val > q->val)
            {
                Node = Node->left;
            }
            else if(Node->val < p->val && Node->val < q->val)
            {
                Node = Node->right;
            }
            else
            {
                break;
            }
        }
        
        return Node;
    }
};
// @lc code=end

