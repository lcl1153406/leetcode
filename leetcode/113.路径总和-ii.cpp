/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

#include <vector>
#include <stack>
#include <numeric>

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
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    	vector<vector<int>> Result;
    	if (!root)
	    {
		    return Result;
	    }
    	vector<int> Arr;
        Arr.push_back(root->val);
    	SearchPathSum(root, targetSum, Arr, Result);
    	return Result;
    }

	void SearchPathSum(TreeNode* Node, int targetSum, vector<int>& Arr, vector<vector<int>>& AllArr)
    {
	    if (!Node)
	    {
		    return;
	    }
	    if (!Node->left && !Node->right)
	    {
		    if (std::accumulate(Arr.begin(), Arr.end(), 0) == targetSum)
		    {
		    	AllArr.push_back(Arr);
		    }
	    	return;
	    }
	    if (Node->left)
	    {
            Arr.push_back(Node->left->val);
	    	SearchPathSum(Node->left, targetSum, Arr, AllArr);
	    	Arr.pop_back();
	    }
	    if (Node->right)
	    {
            Arr.push_back(Node->right->val);
	    	SearchPathSum(Node->right, targetSum, Arr, AllArr);
	    	Arr.pop_back();
	    }
    }
};
// @lc code=end

