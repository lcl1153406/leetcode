//给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,null,2,3]
//输出：[1,3,2]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 2192 👎 0

#include <vector>
#include <stack>

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
	using FItem = std::pair<TreeNode*, bool>;
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> Result;
        if (!root)
        {
	        return Result;
        }
    	stack<FItem> Stack;
    	Stack.emplace(root, false);
        while (!Stack.empty())
        {
	        auto [Node, bFlag] = Stack.top();
        	Stack.pop();
	        if (bFlag)
	        {
		        Result.push_back(Node->val);
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
    	return Result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
