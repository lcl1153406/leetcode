//给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。 
//
// 假设二叉树中至少有一个节点。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: root = [2,1,3]
//输出: 1
// 
//
// 示例 2: 
//
// 
//
// 
//输入: [1,2,3,4,null,5,6,null,null,7]
//输出: 7
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [1,10⁴] 
// 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 616 👎 0

#include <vector>
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
    int findBottomLeftValue(TreeNode* root) {
	    if (!root)
	    {
		    return 0;
	    }

    	queue<TreeNode*> Queue;
    	Queue.push(root);
	    while (!Queue.empty())
	    {
	    	int LeftValue = 0;
		    int Size = Queue.size();
		    for (int i = 0; i < Size; ++i)
		    {
			    auto* Node = Queue.front();
		    	Queue.pop();
			    if (i == 0)
			    {
			    	LeftValue = Node->val;
			    }
			    if (Node->left)
			    {
			    	Queue.push(Node->left);
			    }
			    if (Node->right)
			    {
				    Queue.push(Node->right);
			    }
		    }
		    if (Queue.empty())
		    {
			    return LeftValue;
		    }
	    }
    	return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
