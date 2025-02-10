/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
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
        Vec.push_back(Node->val);
        Traversal(Node->left, Vec);
        Traversal(Node->right, Vec);
    }
*/

// 非递归写法
    vector<int> preorderTraversal(TreeNode* root) {
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
            if (Node->right)
            {
                Stack.push(Node->right);
            }
            if (Node->left)
            {
                Stack.push(Node->left);
            }
        }
        return Result;
    }

};
// @lc code=end

