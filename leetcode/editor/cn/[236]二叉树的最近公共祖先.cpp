//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。 
//
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（
//一个节点也可以是它自己的祖先）。” 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//输出：3
//解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
// 
//
// 示例 2： 
// 
// 
//输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//输出：5
//解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
// 
//
// 示例 3： 
//
// 
//输入：root = [1,2], p = 1, q = 2
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [2, 10⁵] 内。 
// -10⁹ <= Node.val <= 10⁹ 
// 所有 Node.val 互不相同 。 
// p != q 
// p 和 q 均存在于给定的二叉树中。 
// 
//
// Related Topics 树 深度优先搜索 二叉树 👍 2896 👎 0

#include <vector>
#include <queue>
#include <iostream>

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	/*
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
    */
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	TreeNode* Result = nullptr;
    	lowestCommonAncestor_Impl(root, p, q, Result);
    	return Result;
    }

	TreeNode* lowestCommonAncestor_Impl(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& Result) {
		if (!root || root == p || root == q)
		{
			if (root)
			{
				std::cout << "return root :" << root->val << '\n';
			}
			else
			{
				std::cout << "return root :" << "nullptr" << '\n';
			}
			
			return root;
		}
    	TreeNode* LeftNode = lowestCommonAncestor_Impl(root->left, p, q, Result);

    	if (LeftNode)
    	{
    		std::cout << "LeftNode :" << LeftNode->val << '\n';
    	}
    	else
    	{
    		std::cout << "LeftNode :" << "nullptr" << '\n';
    	}
    	
		if (Result)
		{
			std::cout << "Return Result :" << Result->val << '\n';
			return Result;
		}
		else
		{
			std::cout << "LeftNode Result :" << "nullptr" << '\n';
		}
    	TreeNode* RightNode = lowestCommonAncestor_Impl(root->right, p, q, Result);

    	if (RightNode)
    	{
    		std::cout << "RightNode :" << RightNode->val << '\n';
    	}
    	else
    	{
    		std::cout << "RightNode :" << "nullptr" << '\n';
    	}
    	
    	if (Result)
    	{
    		std::cout << "Return Result :" << Result->val << '\n';
    		return Result;
    	}
	    else
	    {
	    	std::cout << "RightNode Result :" << "nullptr" << '\n';
	    }
    	if (LeftNode && RightNode)
    	{
    		Result = root;
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
//leetcode submit region end(Prohibit modification and deletion)
