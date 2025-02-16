/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
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
            int MaxValue = INT32_MIN;
            for (int i = 0; i < Size; i++)
            {
                auto* Node = Queue.front();
                Queue.pop();
                if (Node->val > MaxValue)
                {
                    MaxValue = Node->val;
                }
                if (Node->left)
                {
                    Queue.push(Node->left);
                }
                if (Node->right)
                {
                    Queue.push(Node->right);
                }
            }
            Result.push_back(MaxValue);
        }
        return Result;
    }
};
// @lc code=end

