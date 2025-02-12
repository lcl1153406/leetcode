// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem94.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
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
        Vec.push_back(Node->val);
        Traversal(Node->right, Vec);
    }
*/

// 非递归写法
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> Result;
        if (!root)
        {
            return Result;
        }
        
        stack<TreeNode*> Stack;
        TreeNode* Current = root;
        while (Current || !Stack.empty())
        {
            while (Current)
            {
                Stack.push(Current);
                Current = Current->left;
            }
            
            Current = Stack.top();
            Result.push_back(Current->val);
            Stack.pop();
            Current = Current->right;
        }
        
        return Result;
    }
};
// @lc code=end

