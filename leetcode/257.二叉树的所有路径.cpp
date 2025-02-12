/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    using FItem = pair<TreeNode*, string>;
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> Result;
        if (!root)
        {
            return Result;
        }
        queue<FItem> Queue;
        Queue.emplace(root, to_string(root->val));
        while (!Queue.empty())
        {
            int Size = Queue.size();
            for (int i = 0; i < Size; i++)
            {
                auto [Node, Str] = Queue.front();
                Queue.pop();
                if (Node->left)
                {
                    Queue.emplace(Node->left, Str + "->" + to_string(Node->left->val));
                }
                if (Node->right)
                {
                    Queue.emplace(Node->right, Str + "->" + to_string(Node->right->val));
                }
                if (!Node->left && !Node->right)
                {
                    Result.push_back(Str);
                }
            }
        }
        return Result;
    }
};
// @lc code=end

