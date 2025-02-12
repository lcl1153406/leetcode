/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

    // 递归写法
    // int maxDepth(TreeNode* root) {
    //     if (!root)
    //     {
    //         return 0;
    //     }
        
    //     int MaxLeft = maxDepth(root->left);
    //     int MaxRight = maxDepth(root->right);
    //     return max(MaxLeft, MaxRight) + 1;
    // }

    int maxDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        
        int Result = 0;
        queue<TreeNode*> Queue;
        Queue.push(root);
        while (!Queue.empty())
        {
            Result++;
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
            }
        }
        return Result;
    }
};
// @lc code=end

