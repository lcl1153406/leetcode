// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem501.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

#include <vector>
#include <stack>
#include <optional>
#include <cmath>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

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
    // vector<int> findMode(TreeNode* root) {
    //     vector<int> Result;
    //     TreeNode* LastNode = nullptr;
    //     int CurrentCount = 0;
    //     int MaxCount = 0;
    //     FindMode_Impl(root, LastNode, CurrentCount ,MaxCount, Result);
    //     return Result;
    // }

    // void FindMode_Impl(TreeNode* Node, TreeNode*& LastNode, int& CurrentCount, int& MaxCount, vector<int>& Values)
    // {
    //     if (!Node)
    //     {
    //         return;
    //     }

    //     if (Node->left)
    //     {
    //         FindMode_Impl(Node->left, LastNode, CurrentCount, MaxCount, Values);
    //     }

    //     if (LastNode)
    //     {
    //         if (Node->val == LastNode->val)
    //         {
    //             CurrentCount++;
    //         }
    //         else
    //         {
    //             CurrentCount = 1;
    //         }
    //     }
    //     else
    //     {
    //         CurrentCount = 1;
    //     }

    //     if (CurrentCount == MaxCount)
    //     {
    //         Values.push_back(Node->val);
    //     }
    //     else if (CurrentCount > MaxCount)
    //     {
    //         MaxCount = CurrentCount;
    //         Values.clear();
    //         Values.push_back(Node->val);
    //     }

    //     LastNode = Node;

    //     if (Node->right)
    //     {
    //         FindMode_Impl(Node->right, LastNode, CurrentCount, MaxCount, Values);
    //     }
    // }

    // 迭代写法
    vector<int> findMode(TreeNode* root) {
        vector<int> Values;
        if (!root)
        {
            return Values;
        }
        
        stack<TreeNode*> Stack;
        TreeNode* Node = root;
        TreeNode* LastNode = nullptr;
        int CurrentCount = 0;
        int MaxCount = 0;
        while (Node || !Stack.empty())
        {
            while (Node)
            {
                Stack.push(Node);
                Node = Node->left;
            }
            
            Node = Stack.top();
            Stack.pop();

            if (LastNode)
            {
                if (Node->val == LastNode->val)
                {
                    CurrentCount++;
                }
                else
                {
                    CurrentCount = 1;
                }
            }
            else
            {
                CurrentCount = 1;
            }

            if (CurrentCount == MaxCount)
            {
                Values.push_back(Node->val);
            }
            else if (CurrentCount > MaxCount)
            {
                MaxCount = CurrentCount;
                Values.clear();
                Values.push_back(Node->val);
            }

            LastNode = Node;

            Node = Node->right;
        }
        return Values;
    }
};
// @lc code=end

