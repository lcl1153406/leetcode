/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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

// 递归写法
/*
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> Result;
        Traversal(root, Result);
        return Result;
    }

    void Traversal(TreeNode* Node, vector<int>& Vec)
    {
        if (!Node)
        {
            return;
        }
        Traversal(Node->left, Vec);
        Traversal(Node->right, Vec);
        Vec.push_back(Node->val);
    }
*/

// 非递归写法
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> Result;
        if (!root)
        {
            return Result;
        }

        stack<TreeNode*> Stack;
        Stack.push(root);
        while (!Stack.empty())
        {
            auto* Node = Stack.top();
            Result.push_back(Node->val);
            Stack.pop();
            if (Node->left)
            {
                Stack.push(Node->left);
            }
            if (Node->right)
            {
                Stack.push(Node->right);
            }
        }
        
        reverse(Result.begin(), Result.end());
        
        return Result;
    }
};
// @lc code=end

