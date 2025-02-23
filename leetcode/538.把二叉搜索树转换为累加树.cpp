// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem538.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    // TreeNode* convertBST(TreeNode* root) {
    //     int LastValue = 0;
    //     convertBST_Impl(root, LastValue);
    //     return root;
    // }

    // void convertBST_Impl(TreeNode* root, int& LastValue) {
    //     if (!root)
    //     {
    //         return;
    //     }
        
    //     convertBST_Impl(root->right, LastValue);

    //     root->val += LastValue;
    //     LastValue = root->val;

    //     convertBST_Impl(root->left, LastValue);
    // }

    // 迭代写法
    // TreeNode* convertBST(TreeNode* root) {
    //     if (!root)
    //     {
    //         return nullptr;
    //     }
        
    //     int LastValue = 0;
    //     stack<TreeNode*> Stack;
    //     TreeNode* Cur = root;
    //     while (Cur || !Stack.empty())
    //     {
    //         while (Cur)
    //         {
    //             Stack.push(Cur);
    //             Cur = Cur->right;
    //         }
            
    //         Cur = Stack.top();
    //         Stack.pop();
    //         Cur->val += LastValue;
    //         LastValue = Cur->val;
    //         Cur = Cur->left;
    //     }
    //     return root;
    // }

    // 迭代写法
    using FItem = std::pair<TreeNode*, bool>;
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
        {
            return nullptr;
        }
        
        int LastValue = 0;
        stack<FItem> Stack;
        Stack.emplace(root, false);
        while (!Stack.empty())
        {
            auto [Node, bFlag] = Stack.top();
            Stack.pop();
            if (bFlag)
            {
                Node->val += LastValue;
                LastValue = Node->val;
            }
            else
            {
                if (Node->left)
                {
                    Stack.emplace(Node->left, false);
                }
                Stack.emplace(Node, true);
                if (Node->right)
                {
                    Stack.emplace(Node->right, false);
                }
            }
        }
        return root;
    }
};
// @lc code=end

