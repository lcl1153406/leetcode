/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

 #include <utility>
 #include <stack>
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

    // 递归--后序遍历
    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root)
    //     {
    //         return nullptr;
    //     }
        
    //     invertTree(root->left);
    //     invertTree(root->right);
    //     std::swap(root->left, root->right);
    //     return root;
    // }

    //递归--前序遍历
    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root)
    //     {
    //         return nullptr;
    //     }
        
    //     std::swap(root->left, root->right);
    //     invertTree(root->left);
    //     invertTree(root->right);
    //     return root;
    // }

    //迭代--前序遍历1
    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root)
    //     {
    //         return nullptr;
    //     }
        
    //     stack<TreeNode*> Stack;
    //     Stack.push(root);
    //     while (!Stack.empty())
    //     {
    //         auto* Node = Stack.top();
    //         Stack.pop();
    //         swap(Node->left, Node->right);
    //         if (Node->right)
    //         {
    //             Stack.push(Node->right);
    //         }
    //         if (Node->left)
    //         {
    //             Stack.push(Node->left);
    //         }
    //     }
    //     return root;
    // }

    //迭代--前序遍历2
    // using FItem = pair<TreeNode*, bool>;
    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root)
    //     {
    //         return nullptr;
    //     }
        
    //     stack<FItem> Stack;
    //     Stack.emplace(root, false);
    //     while (!Stack.empty())
    //     {
    //         auto [Node, bFlag] = Stack.top();
    //         Stack.pop();

    //         if (bFlag)
    //         {
    //             swap(Node->left, Node->right);
    //         }
    //         else
    //         {
    //             if (Node->right)
    //             {
    //                 Stack.emplace(Node->right, false);
    //             }
    //             if (Node->left)
    //             {
    //                 Stack.emplace(Node->left, false);
    //             }
    //             Stack.emplace(Node, true);
    //         }  
    //     }
    //     return root;
    // }

    //层序遍历
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
        {
            return nullptr;
        }
        
        queue<TreeNode*> Queue;
        Queue.push(root);
        while (!Queue.empty())
        {
            int Size = Queue.size();
            for (int i = 0; i < Size; i++)
            {
                auto* Node = Queue.front();
                Queue.pop();
                swap(Node->left, Node->right);

                if (Node->left)
                {
                    Queue.push(Node->left);
                }
                if (Node->right)
                {
                    Queue.push(Node->right);
                }
            } 
        }
        return root;
    }
};
// @lc code=end

