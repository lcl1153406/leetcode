//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,3,null,5]
//输出：["1->2->5","1->3"]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：["1"]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [1, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 字符串 回溯 二叉树 👍 1201 👎 0

#include <vector>
#include <string>

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
    vector<string> binaryTreePaths(TreeNode* root) {
    	vector<string> Result;
    	SearchTreePaths(root, "", Result);
    	return Result;
    }

	void SearchTreePaths(TreeNode* Node, string Path, vector<string>& AllPaths)
    {
	    if (!Node)
	    {
		    return;
	    }

    	Path += to_string(Node->val);
	    if (!Node->left && !Node->right)
	    {
		    AllPaths.push_back(Path);
	    	return;
	    }
	    if (Node->left)
	    {
	    	SearchTreePaths(Node->left, Path + "->", AllPaths);
	    }
	    if (Node->right)
	    {
	    	SearchTreePaths(Node->right, Path + "->", AllPaths);
	    }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
