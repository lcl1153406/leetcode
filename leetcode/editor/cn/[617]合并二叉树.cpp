//给你两棵二叉树： root1 和 root2 。 
//
// 想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠
//，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。 
//
// 返回合并后的二叉树。 
//
// 注意: 合并过程必须从两个树的根节点开始。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
//输出：[3,4,5,5,4,null,7]
// 
//
// 示例 2： 
//
// 
//输入：root1 = [1], root2 = [1,2]
//输出：[2,2]
// 
//
// 
//
// 提示： 
//
// 
// 两棵树中的节点数目在范围 [0, 2000] 内 
// -10⁴ <= Node.val <= 10⁴ 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1442 👎 0

#include <iostream>
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
    // TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
	   //  if (!root1 && !root2)
	   //  {
	   //  	std::cout << "roo1 = null, root2 = null" << "\n";
		  //   return nullptr;
	   //  }
	   //  if (root1 && !root2)
	   //  {
	   //  	std::cout << "roo1 = "<< root1->val << ", root2 = null" << "\n";
		  //   // return new TreeNode{root1->val};  这么写有bug
	   //  	return root1;
	   //  }
	   //  if (!root1 && root2)
	   //  {
	   //  	std::cout << "roo1 = null, root2 = "<< root2->val << "\n";
		  //   //return new TreeNode{root2->val};   这么写有bug
	   //  	return root2;
	   //  }
    //
    // 	std::cout << "roo1 = "<< root1->val << ", root2 = "<< root2->val << "\n";
    // 	TreeNode* Node = new TreeNode{root1->val + root2->val};
    // 	std::cout << "mergeTrees left" << "\n";
    // 	Node->left = mergeTrees(root1->left, root2->left);
    // 	std::cout << "mergeTrees right" << "\n";
    // 	Node->right = mergeTrees(root1->right, root2->right);
    // 	std::cout << "return" << "\n";
    // 	return Node;
    // }

	// TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
	// 	if (!root1)
	// 	{
	// 		return root2;
	// 	}
	// 	if(!root2)
	// 	{
	// 		return root1;	
	// 	}
	//
	// 	root1->val += root2->val;
	// 	root1->left = mergeTrees(root1->left, root2->left);
	// 	root1->right = mergeTrees(root1->right, root2->right);
	// 	return root1;
	// }

	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (!root1)
		{
			return root2;
		}
		if (!root2)
		{
			return root1;
		}

		queue<pair<TreeNode*, TreeNode*>> Queue;
		Queue.emplace(root1, root2);
		while (!Queue.empty())
		{
			auto [Node1, Node2] = Queue.front();
			Queue.pop();
			Node1->val += Node2->val;

			if (Node1->left && Node2->left)
			{
				Queue.emplace(Node1->left, Node2->left);
			}
			if (Node1->right && Node2->right)
			{
				Queue.emplace(Node1->right, Node2->right);
			}
			if (!Node1->left && Node2->left)
			{
				Node1->left = Node2->left;
			}
			if (!Node1->right && Node2->right)
			{
				Node1->right = Node2->right;
			}
		}
		return root1;
	}	
};
//leetcode submit region end(Prohibit modification and deletion)
