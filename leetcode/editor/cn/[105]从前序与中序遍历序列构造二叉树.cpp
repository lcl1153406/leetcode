//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并
//返回其根节点。 
//
// 
//
// 示例 1: 
// 
// 
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//输出: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [-1], inorder = [-1]
//输出: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder 和 inorder 均 无重复 元素 
// inorder 均出现在 preorder 
// preorder 保证 为二叉树的前序遍历序列 
// inorder 保证 为二叉树的中序遍历序列 
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 2462 👎 0

#include <iostream>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	    if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size())
	    {
		    return nullptr;
	    }
    	return BuildTree_Impl(preorder, 0 , preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

	TreeNode* BuildTree_Impl(vector<int>& PreOrder, int PreStart, int PreEnd, vector<int>& InOrder, int InStart, int InEnd)
    {
	    if (PreStart > PreEnd)
	    {
		    return nullptr;
	    }

    	TreeNode* Root = new TreeNode{PreOrder[PreStart]};
	    if (PreStart == PreEnd)
	    {
		    return Root;
	    }

    	int SplitIndex = InStart;
	    for (int i = InStart; i <= InEnd; ++i)
	    {
		    if (PreOrder[PreStart] == InOrder[i])
		    {
		    	SplitIndex = i;
		    	break;
		    }
	    }

    	int LeftInStart = InStart;
    	int LeftInEnd = SplitIndex - 1;
    	int RightInStart = SplitIndex + 1;
    	int RightInEnd = InEnd;

    	cout << "InOrderIndex: " << LeftInStart << LeftInEnd << RightInStart << RightInEnd << '\n';

    	int LeftPreStart = PreStart + 1;
    	int LeftPreEnd = LeftPreStart + LeftInEnd - LeftInStart;
    	int RightPreStart = LeftPreEnd + 1;
    	int RightPreEnd = PreEnd;

    	cout<< "PostOrderIndex: " << LeftPreStart << LeftPreEnd << RightPreStart << RightPreEnd << '\n';

    	Root->left = BuildTree_Impl(PreOrder, LeftPreStart, LeftPreEnd, InOrder,LeftInStart, LeftInEnd);
    	Root->right = BuildTree_Impl(PreOrder, RightPreStart, RightPreEnd, InOrder, RightInStart, RightInEnd);
    	return Root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
