// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem701.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    // 递归写法1
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     if (!root)
    //     {
    //         return new TreeNode{val};
    //     }
        
    //     if (root->val > val)
    //     {
    //         root->left = insertIntoBST(root->left, val);
    //     }
    //     else
    //     {
    //         root->right = insertIntoBST(root->right, val);
    //     }

    //     return root;
    // }

    // 递归写法2
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     if (!root)
    //     {
    //         return new TreeNode{val};
    //     }
        
    //     insertIntoBST_Impl(root, val, root);

    //     return root;
    // }

    // void insertIntoBST_Impl(TreeNode* Node, int val, TreeNode* Parent) {
    //     if (!Node)
    //     {
    //         if (Parent->val > val)
    //         {
    //             Parent->left = new TreeNode{val};
    //         }
    //         else
    //         {
    //             Parent->right = new TreeNode{val};
    //         }
    //         return;
    //     }
        
    //     if (Node->val > val)
    //     {
    //         insertIntoBST_Impl(Node->left, val, Node);
    //     }
    //     else
    //     {
    //         insertIntoBST_Impl(Node->right, val, Node);
    //     }
    // }

    // 迭代写法1
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     if (!root)
    //     {
    //         return new TreeNode{val};
    //     }
        
    //     TreeNode* Node = root;
    //     while (Node)
    //     {
    //         if (Node->val > val)
    //         {
    //             if (!Node->left)
    //             {
    //                 Node->left = new TreeNode{val};
    //                 break;
    //             }
    //             else
    //             {
    //                 Node = Node->left;
    //             }
    //         }
    //         else
    //         {
    //             if (!Node->right)
    //             {
    //                 Node->right = new TreeNode{val};
    //                 break;
    //             }
    //             else
    //             {
    //                 Node = Node->right;
    //             }
    //         }
    //     }

    //     return root;
    // }

    // 迭代写法1
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
        {
            return new TreeNode{val};
        }
        
        TreeNode* Node = root;
        TreeNode* Parent = root;
        while (Node)
        {
            Parent = Node;
            if (Node->val > val)
            {
                 Node = Node->left; 
            }
            else
            {
                Node = Node->right;
            }
        }

        if (Parent->val > val)
        {
            Parent->left = new TreeNode{val};
        }
        else
        {
            Parent->right = new TreeNode{val};
        }

        return root;
    }
};
// @lc code=end

