// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem669.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
 */

#include <vector>
#include <stack>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

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
    // TreeNode* trimBST(TreeNode* root, int low, int high) {
    //     if (!root)
    //     {
    //         return nullptr;
    //     }

    //     if (root->val < low)
    //     {
    //         return trimBST(root->right, low, high);
    //     }
    //     else if (root->val > high)
    //     {
    //         return trimBST(root->left, low, high);
    //     }
        
    //     root->left = trimBST(root->left, low, high);
    //     root->right = trimBST(root->right, low, high);

    //     return root;
    // }

    // 迭代写法
    // TreeNode* trimBST(TreeNode* root, int low, int high) {
    //     if (!root)
    //     {
    //         return nullptr;
    //     }

    //     while (root)
    //     {
    //         if (root->val < low)
    //         {
    //             root = root->right;
    //         }
    //         else if (root->val > high)
    //         {
    //             root = root->left;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
        
    //     if (!root)
    //     {
    //         return nullptr;
    //     }
        
    //     TreeNode* Pre = root;
    //     TreeNode* Cur = root->left;
    //     while (Cur)
    //     {
    //         if (Cur->val < low)
    //         {
    //             Cur = Cur->right;
    //             Pre->left = Cur;
    //         }
    //         else
    //         {
    //             Pre = Cur;
    //             Cur = Cur->left;
    //         }
    //     }
        
    //     Pre = root;
    //     Cur = root->right;
    //     while (Cur)
    //     {
    //         if (Cur->val > high)
    //         {
    //             Cur = Cur->left;
    //             Pre->right = Cur;
    //         }
    //         else
    //         {
    //             Pre = Cur;
    //             Cur = Cur->right;
    //         }
    //     }
        
    //     return root;
    // }

    // 迭代写法
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root)
        {
            return nullptr;
        }

        while (root && (root->val < low || root->val > high))
        {
            if(root->val < low)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        
        TreeNode* Cur = root;

        while (Cur)
        {
            while (Cur->left && Cur->left->val < low)
            {
                Cur->left = Cur->left->right;
            }
            
            Cur = Cur->left;
        }
        
        Cur = root;
        while (Cur)
        {
            while (Cur->right && Cur->right->val > high)
            {
                Cur->right = Cur->right->left;
            }
            
            Cur = Cur->right;
        }
        
        return root;
    }
};
// @lc code=end

