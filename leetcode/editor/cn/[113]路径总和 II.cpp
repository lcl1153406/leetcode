//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 
// 
// 
// 
// 
//
// 示例 1： 
// 
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：[[5,4,11,2],[5,8,4,5]]
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,3], targetSum = 5
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1,2], targetSum = 0
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点总数在范围 [0, 5000] 内 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
//
// Related Topics 树 深度优先搜索 回溯 二叉树 👍 1167 👎 0

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

//leetcode submit region begin(Prohibit modification and deletion)
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
    	SearchPathSum(root, targetSum, Arr, Result);
    	return Result;
    }

	void SearchPathSum(TreeNode* Node, int targetSum, vector<int>& Arr, vector<vector<int>>& AllArr)
    {
	    if (!Node)
	    {
		    return;
	    }
    	Arr.push_back(Node->val);
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
	    	SearchPathSum(Node->left, targetSum, Arr, AllArr);
	    	Arr.pop_back();
	    }
	    if (Node->right)
	    {
	    	SearchPathSum(Node->right, targetSum, Arr, AllArr);
	    	Arr.pop_back();
	    }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
