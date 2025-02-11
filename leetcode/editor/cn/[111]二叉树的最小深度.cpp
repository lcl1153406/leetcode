//给定一个二叉树，找出其最小深度。 
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 
//
// 说明：叶子节点是指没有子节点的节点。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：root = [2,null,3,null,4,null,5,null,6]
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数的范围在 [0, 10⁵] 内 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1255 👎 0

#include <utility>

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
    int minDepth(TreeNode* root) {
	    if (!root)
	    {
		    return 0;
	    }
    	int MinDepth = INT32_MAX;
    	GetDepth(root, 1, MinDepth);
    	return MinDepth;
    }

	void GetDepth(TreeNode* Node, int Depth, int& MinDepth)
    {
    	if (!Node)
    	{
    		return;
    	}
	    if (!Node->left && !Node->right)
	    {
	    	MinDepth = std::min(Depth, MinDepth);
		    return;
	    }
    	
	    if (Node->left)
	    {
	    	GetDepth(Node->left, Depth + 1, MinDepth);
	    }
    	if (Node->right)
    	{
    		GetDepth(Node->right, Depth + 1, MinDepth);
    	}
    }
};
//leetcode submit region end(Prohibit modification and deletion)
