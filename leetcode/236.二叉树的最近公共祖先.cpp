// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem236.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if (!root || root == p || root == q)
		{
			return root;
		}
    	TreeNode* LeftNode = lowestCommonAncestor(root->left, p, q);
    	TreeNode* RightNode = lowestCommonAncestor(root->right, p, q);

    	if (LeftNode && RightNode)
    	{
    		return root;
    	}
    	else if (!LeftNode && RightNode)
    	{
    		return RightNode;
    	}
    	else if(LeftNode && !RightNode)
    	{
    		return LeftNode;
    	}
    	else
    	{
    		return nullptr;
    	}
    }
};
// @lc code=end

