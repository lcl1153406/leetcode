// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem450.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    // TreeNode* deleteNode(TreeNode* root, int key) {
    //     if (!root)
    //     {
    //         return nullptr;
    //     }
    //     if (root->val == key)
    //     {
    //         if (!root->left && !root->right)
    //         {
    //             return nullptr;
    //         }
    //         if (root->left && !root->right)
    //         {
    //             return root->left;
    //         }
    //         if (!root->left && root->right)
    //         {
    //             return root->right;
    //         }
    //         if (root->left && root->right)
    //         {
    //             TreeNode* Cur = root->right;
    //             while (Cur->left)
    //             {
    //                 Cur = Cur->left;
    //             }
    //             Cur->left = root->left;
    //             return root->right;
    //         }
    //     }
            
    //     if (root->val > key)
    //     {
    //         root->left = deleteNode(root->left, key);
    //     }
    //     else
    //     {
    //         root->right = deleteNode(root->right, key);
    //     }
    //     return root;
    // }

    // 迭代写法
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
        {
            return nullptr;
        }
        
        TreeNode* Cur = root;
        TreeNode* Pre = nullptr;
        while (Cur)
        {
            if (Cur->val == key)
            {
                break;
            }
            Pre = Cur;
            if (Cur->val > key)
            {
                Cur = Cur->left;
            }
            else
            {
                Cur = Cur->right;
            }
        }
        
        if (Pre == nullptr)
        {
            return DeleteCurrentNode(Cur, key);
        }
        
        if (Pre->left && Pre->left == Cur)
        {
            Pre->left = DeleteCurrentNode(Pre->left ,key);
        }
        if (Pre->right && Pre->right == Cur)
        {
            Pre->right = DeleteCurrentNode(Pre->right ,key);
        }

        return root;
    }

    TreeNode* DeleteCurrentNode(TreeNode* Node, int key)
    {
        if (!Node)
        {
            return nullptr;
        }
        if (!Node->left && !Node->right)
        {
            return nullptr;
        }
        if (Node->left && !Node->right)
        {
            return Node->left;
        }
        if (!Node->left && Node->right)
        {
            return Node->right;
        }
        TreeNode* Cur = Node->right;
        while (Cur->left)
        {
            Cur = Cur->left;
        }
        Cur->left = Node->left;
        return Node->right;
    }

    // 更精简的写法，比较绕
    // TreeNode* deleteNode(TreeNode* root, int key) {
    //     if (root == nullptr) return root;
    //     if (root->val == key) {
    //         if (root->right == nullptr) { // 这里第二次操作目标值：最终删除的作用
    //             return root->left;
    //         }
    //         TreeNode *cur = root->right;
    //         while (cur->left) {
    //             cur = cur->left;
    //         }
    //         swap(root->val, cur->val); // 这里第一次操作目标值：交换目标值其右子树最左面节点。
    //     }
    //     root->left = deleteNode(root->left, key);
    //     root->right = deleteNode(root->right, key);
    //     return root;
    // }
};
// @lc code=end

