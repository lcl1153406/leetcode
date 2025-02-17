/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> Result;
        if (!root)
        {
            return Result;
        }
        queue<TreeNode*> Queue;
        Queue.push(root);
        while (!Queue.empty())
        {
            int Size = Queue.size();
            double Sum = 0.0;
            for (int i = 0; i < Size; i++)
            {
                auto* Node = Queue.front();
                Queue.pop();
                Sum += Node->val;
                if (Node->left)
                {
                    Queue.push(Node->left);
                }
                if (Node->right)
                {
                    Queue.push(Node->right);
                }
            }
            Result.push_back(Sum / Size);
        }
        return Result;
    }
};
// @lc code=end

