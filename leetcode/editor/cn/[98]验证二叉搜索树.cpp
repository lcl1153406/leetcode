//给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。 
//
// 有效 二叉搜索树定义如下： 
//
// 
// 节点的左子树只包含 小于 当前节点的数。 
// 节点的右子树只包含 大于 当前节点的数。 
// 所有左子树和右子树自身必须也是二叉搜索树。 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [2,1,3]
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：root = [5,1,4,null,null,3,6]
//输出：false
//解释：根节点的值是 5 ，但是右子节点的值是 4 。
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目范围在[1, 10⁴] 内 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 2496 👎 0


#include <vector>
#include <stack>
#include <queue>
#include <optional>

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
	/* 递归写法
    bool isValidBST(TreeNode* root) {
	    if (!root)
	    {
		    return true;
	    }
		std::optional<int> LastValue;
    	return isValidBST_Impl(root, LastValue);
    }

	bool isValidBST_Impl(TreeNode* Node, std::optional<int>& LastValue)
    {
		if (!Node) 
		{
			return true;
		}	
    	if (Node->left)
    	{
		    if (!isValidBST_Impl(Node->left, LastValue))
		    {
			    return false;
		    }
    	}
	    if (LastValue.has_value() && Node->val <= LastValue.value())
	    {
		    return false;
	    }
	    else
	    {
	    	LastValue = Node->val;
	    }
	    if (Node->right)
	    {
		    if (!isValidBST_Impl(Node->right, LastValue))
		    {
		    	return false;
		    }
	    }
    	return true;
    }
    */

	// 迭代写法
	using FItem = std::pair<TreeNode*, bool>;
	bool isValidBST(TreeNode* root) {
		if (!root)
		{
			return true;
		}
		optional<int> LastValue;
		stack<FItem> Stack;
		Stack.emplace(root, false);
		while (!Stack.empty())
		{
			auto [Node, bFlag] = Stack.top();
			Stack.pop();
			if (bFlag)
			{
				if (LastValue.has_value() && Node->val <= LastValue.value())
				{
					return false;
				}
				LastValue = Node->val;
			}
			else
			{
				if (Node->right)
				{
					Stack.emplace(Node->right, false);
				}
				Stack.emplace(Node, true);
				if (Node->left)
				{
					Stack.emplace(Node->left, false);
				}
			}
		}
		return true;
	}
};
//leetcode submit region end(Prohibit modification and deletion)
