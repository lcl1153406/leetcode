//给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历） 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[15,7],[9,20],[3]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[[1]]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 2000] 内 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics 树 广度优先搜索 二叉树 👍 825 👎 0

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> Result;
	    if (!root)
	    {
		    return Result;
	    }
    	queue<TreeNode*> Queue;
    	Queue.push(root);
	    while (!Queue.empty())
	    {
		    int Size = Queue.size();
	    	vector<int> Temp;
		    for (int i = 0; i < Size; ++i)
		    {
			    auto* Node = Queue.front();
		    	Queue.pop();
		    	Temp.push_back(Node->val);
		    	
			    if (Node->left)
			    {
				    Queue.push(Node->left);
			    }
		    	if (Node->right)
		    	{
		    		Queue.push(Node->right);
		    	}
		    }
	    	Result.push_back(Temp);
	    }
    	reverse(Result.begin(), Result.end());
    	return Result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
