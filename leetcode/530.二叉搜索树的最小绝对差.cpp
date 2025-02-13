/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

#include <vector>
#include <stack>
#include <optional>
#include <cmath>

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
    int getMinimumDifference(TreeNode* root) {
        optional<int> LastValue;
        int DiffValue = INT32_MAX;
        GetMiniDiff(root, LastValue, DiffValue);
        return DiffValue;
    }

    void GetMiniDiff(TreeNode* Node, optional<int>& LastValue, int& DiffValue)
    {
        if (!Node)
        {
            return;
        }
        GetMiniDiff(Node->left, LastValue, DiffValue);
        if (LastValue.has_value())
        {
            DiffValue = min(Node->val - LastValue.value(), DiffValue);
        }
        LastValue = Node->val;
        GetMiniDiff(Node->right, LastValue, DiffValue);
    }

    // 迭代写法
    // using FItem = pair<TreeNode*, bool>;
    // int getMinimumDifference(TreeNode* root) {
    //     if (!root)
    //     {
    //         return 0;
    //     }
        
    //     int DiffValue = INT_MAX;
    //     TreeNode* LastNode = nullptr;
    //     stack<FItem> Stack;
    //     Stack.emplace(root, false);
    //     while (!Stack.empty())
    //     {
    //         auto [Node ,bFlag] = Stack.top();
    //         Stack.pop();

    //         if (bFlag)
    //         {
    //             if (LastNode)
    //             {
    //                 DiffValue = min(Node->val - LastNode->val, DiffValue);
    //             }
    //             LastNode = Node;
    //         }
    //         else
    //         {
    //             if (Node->right)
    //             {
    //                 Stack.emplace(Node->right, false);
    //             }
    //             Stack.emplace(Node, true);
    //             if (Node->left)
    //             {
    //                 Stack.emplace(Node->left, false);
    //             }
    //         }
    //     }
    //     return DiffValue;
    // }
};
// @lc code=end

