/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

#include <vector>
#include <string>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> Result;
        if (!root)
        {
            return Result;
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
                if (Node->left)
                {
                    Queue.push(Node->left);
                }
                if (Node->right)
                {
                    Queue.push(Node->right);
                }
            
                if (i == Size - 1)
                {
                    Result.push_back(Node->val);       
                }
            }
        }
        return Result;
    }
};
// @lc code=end

