/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // 递归写法
    // bool isSymmetric(TreeNode* root) {
    //     if (!root)
    //     {
    //         return true;
    //     }
    //     return Compare(root->left, root->right);
    // }

    // bool Compare(TreeNode* Left, TreeNode* Right)
    // {
    //     if (!Left && !Right)
    //     {
    //         return true;
    //     }
    //     if (!Left || !Right || Left->val != Right->val)
    //     {
    //         return false;
    //     }
        
    //     return Compare(Left->left, Right->right) && Compare(Left->right, Right->left);
    // }

    // 迭代写法
    bool isSymmetric(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        
        queue<TreeNode*> Queue;
        Queue.push(root->left);
        Queue.push(root->right);
        while (!Queue.empty())
        {
            auto* Node1 = Queue.front();
            Queue.pop();
            auto* Node2 = Queue.front();
            Queue.pop();
            if (!Node1 && !Node2)
            {
                continue;
            }
            if (!Node1 || !Node2 || Node1->val != Node2->val)
            {
                return false;
            }
            Queue.push(Node1->left);
            Queue.push(Node2->right);
            Queue.push(Node1->right);
            Queue.push(Node2->left);
        }
        return true;
    }
};
// @lc code=end

