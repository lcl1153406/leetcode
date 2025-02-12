/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

 #include <utility>
 #include <cmath>
 #include <queue>
 #include <stack>

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
    // 递归方式
    // bool isBalanced(TreeNode* root) {
    //     if (!root)
    //     {
    //         return true;
    //     }
    //     return GetDepth(root) != -1;
    // }

    // int GetDepth(TreeNode* Node)
    // {
    //     if (!Node)
    //     {
    //         return 0;
    //     }
    //     int LeftDepth = GetDepth(Node->left);
    //     if (LeftDepth == -1)
    //     {
    //         return -1;
    //     }
        
    //     int RightDepth = GetDepth(Node->right);
    //     if (RightDepth == -1)
    //     {
    //         return -1;
    //     }

    //     if (std::abs(LeftDepth - RightDepth) > 1)
    //     {
    //         return -1;
    //     }
        
    //     return std::max(LeftDepth, RightDepth) + 1;
    // }


    // 递归写法2--求节点深度用后序遍历，判断每个节点是否平衡用前序遍历
    bool isBalanced(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        int LeftDepth = GetDepth(root->left);
        int RightDepth = GetDepth(root->right);
        if (std::abs(LeftDepth - RightDepth) > 1)
        {
            return false;
        }

        bool bLeftBalanced = isBalanced(root->left);
        bool bRightBalanced = isBalanced(root->right);
        
        return bLeftBalanced && bRightBalanced;
    }

    int GetDepth(TreeNode* Node)
    {
        if (!Node)
        {
            return 0;
        }
        int LeftDepth = GetDepth(Node->left);
        int RightDepth = GetDepth(Node->right);
        return std::max(LeftDepth, RightDepth) + 1;
    }

    // 递归写法3--求节点深度用后序遍历，判断每个节点是否平衡用后序遍历
    // bool isBalanced(TreeNode* root) {
    //     if (!root)
    //     {
    //         return true;
    //     }
        
    //     bool bLeftBalanced = isBalanced(root->left);
    //     if (!bLeftBalanced)
    //     {
    //         return false;
    //     }
    //     bool bRightBalanced = isBalanced(root->right);
    //     if (!bRightBalanced)
    //     {
    //         return false;
    //     }
        
    //     int LeftDepth = GetDepth(root->left);
    //     int RightDepth = GetDepth(root->right);
    //     if (std::abs(LeftDepth - RightDepth) > 1)
    //     {
    //         return false;
    //     }
        
    //     return true;
    // }

    // int GetDepth(TreeNode* Node)
    // {
    //     if (!Node)
    //     {
    //         return 0;
    //     }
    //     int LeftDepth = GetDepth(Node->left);
    //     int RightDepth = GetDepth(Node->right);
    //     return std::max(LeftDepth, RightDepth) + 1;
    // }

    // 迭代法--求节点深度用层序遍历，判断每个节点是否平衡用前序遍历
    // bool isBalanced(TreeNode* root) {
    //     if (!root)
    //     {
    //         return true;
    //     }
        
    //     std::stack<TreeNode*> Stack;
    //     Stack.push(root);
    //     while (!Stack.empty())
    //     {
    //         auto* Node = Stack.top();
    //         Stack.pop();
    //         int LeftDepth = GetDepth(Node->left);
    //         int RightDepth = GetDepth(Node->right);
    //         if (std::abs(LeftDepth - RightDepth) > 1)
    //         {
    //             return false;
    //         }
    //         if (Node->right)
    //         {
    //             Stack.push(Node->right);
    //         }
            
    //         if (Node->left)
    //         {
    //             Stack.push(Node->left);
    //         }
    //     }
    //     return true;
    // }

    // int GetDepth(TreeNode* Node)
    // {
    //     if (!Node)
    //     {
    //         return 0;
    //     }
        
    //     int Depth = 0;
    //     std::queue<TreeNode*> Queue;
    //     Queue.push(Node);
    //     while (!Queue.empty())
    //     {
    //         Depth++;
    //         int Size = Queue.size();
    //         for (int i = 0; i < Size; i++)
    //         {
    //             auto* Node = Queue.front();
    //             Queue.pop();
    //             if (Node->left)
    //             {
    //                 Queue.push(Node->left);
    //             }
    //             if (Node->right)
    //             {
    //                 Queue.push(Node->right);
    //             }
    //         }
    //     }
    //     return Depth;
    // }
};
// @lc code=end

