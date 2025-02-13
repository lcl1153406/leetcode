//给定二叉搜索树（BST）的根节点
// root 和一个整数值
// val。 
//
// 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回
// null 。 
//
// 
//
// 示例 1: 
//
// 
// 
//
// 
//输入：root = [4,2,7,1,3], val = 2
//输出：[2,1,3]
// 
//
// 示例 2: 
// 
// 
//输入：root = [4,2,7,1,3], val = 5
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数在 [1, 5000] 范围内 
// 1 <= Node.val <= 10⁷ 
// root 是二叉搜索树 
// 1 <= val <= 10⁷ 
// 
//
// Related Topics 树 二叉搜索树 二叉树 👍 493 👎 0

#include <vector>
#include <stack>
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
	/*
    TreeNode* searchBST(TreeNode* root, int val) {
	    if (!root)
	    {
		    return nullptr;
	    }

	    if (root->val == val)
	    {
		    return root;
	    }
    	else if (root->val > val)
	    {
		    return searchBST(root->left, val);
	    }
	    else
	    {
	    	return searchBST(root->right, val);
	    }
    }
    */
    
    
	// TreeNode* searchBST(TreeNode* root, int val) {
	// 	if (!root)
	// 	{
	// 		return nullptr;
	// 	}
	// 	
	// 	stack<TreeNode*> Stack;
	// 	Stack.push(root);
	// 	while (!Stack.empty())
	// 	{
	// 		auto* Node = Stack.top();
	// 		Stack.pop();
	// 		if (Node->val == val)
	// 		{
	// 			return Node;
	// 		}
	// 		if (Node->val > val && Node->left)
	// 		{
	// 			Stack.push(Node->left);
	// 		}
	// 		else if(Node->val < val && Node->right)
	// 		{
	// 			Stack.push(Node->right);
	// 		}
	// 	}
	// 	return nullptr;
	// }

	// TreeNode* searchBST(TreeNode* root, int val) {
	// 	if (!root)
	// 	{
	// 		return nullptr;
	// 	}
	// 	
	// 	queue<TreeNode*> Queue;
	// 	Queue.push(root);
	// 	while (!Queue.empty())
	// 	{
	// 		auto* Node = Queue.front();
	// 		Queue.pop();
	// 		if (Node->val == val)
	// 		{
	// 			return Node;
	// 		}
	// 		if (Node->val > val && Node->left)
	// 		{
	// 			Queue.push(Node->left);
	// 		}
	// 		else if(Node->val < val && Node->right)
	// 		{
	// 			Queue.push(Node->right);
	// 		}
	// 	}
	// 	return nullptr;
	// }

	TreeNode* searchBST(TreeNode* root, int val) {
		if (!root)
		{
			return nullptr;
		}
		
		TreeNode* Node = root;
		while (Node)
		{
			if (Node->val > val)
			{
				Node = Node->left;
			}
			else if(Node->val < val)
			{
				Node = Node->right;
			}
			else
			{
				return Node;
			}
		}
		return nullptr;
	}
};
//leetcode submit region end(Prohibit modification and deletion)
