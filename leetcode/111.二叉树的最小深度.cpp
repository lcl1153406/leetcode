/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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

    // 迭代写法
    // int minDepth(TreeNode* root) {
    //     if (!root)
    //     {
    //         return 0;
    //     }
        
    //     int Result = 0;
    //     queue<TreeNode*> Queue;
    //     Queue.push(root);
    //     while (!Queue.empty())
    //     {
    //         Result++;
    //         int Size = Queue.size();
    //         for (int i = 0; i < Size; i++)
    //         {
    //             auto* Node = Queue.front();
    //             Queue.pop();
    //             if (!Node->left && !Node->right)
    //             {
    //                 return Result;
    //             }
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
    //     return Result;
    // }

    // 递归写法
    // int minDepth(TreeNode* root) {
    //     if (!root)
    //     {
    //         return 0;
    //     }
    //     int minLeft = minDepth(root->left);
    //     int minRight = minDepth(root->right);

    //     if (!root->left && root->right)
    //     {
    //         return minRight + 1;
    //     }
    //     if (root->left && !root->right)
    //     {
    //         return minLeft + 1;
    //     }

    //     return min(minLeft, minRight) + 1;
    // }


    void getdepth(TreeNode* node, int depth, int& result) {

        if (!node->left && !node->right){
            result = min(result, depth);
            return;
        }

        if (node->left) { // 左
            getdepth(node->left, depth + 1, result);
        }
        if (node->right) { // 右
            getdepth(node->right, depth + 1, result);
        }
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int result = INT_MAX;
        getdepth(root, 1, result);
        return result;
    }
};
// @lc code=end

