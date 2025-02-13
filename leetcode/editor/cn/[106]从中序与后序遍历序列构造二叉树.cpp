//给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并
//返回这颗 二叉树 。 
//
// 
//
// 示例 1: 
// 
// 
//输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//输出：[3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入：inorder = [-1], postorder = [-1]
//输出：[-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= inorder.length <= 3000 
// postorder.length == inorder.length 
// -3000 <= inorder[i], postorder[i] <= 3000 
// inorder 和 postorder 都由 不同 的值组成 
// postorder 中每一个值都在 inorder 中 
// inorder 保证是树的中序遍历 
// postorder 保证是树的后序遍历 
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 1309 👎 0

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	    if (inorder.size() == 0 || postorder.size() == 0 || inorder.size() != postorder.size())
	    {
		    return nullptr;
	    }
        return BuildTree_Impl(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

	TreeNode* BuildTree_Impl(vector<int>& InOrder, int InStart, int InEnd, vector<int>& PostOrder, int PostStart, int PostEnd)
    {
	    if (PostStart > PostEnd)
	    {
		    return nullptr;
	    }

    	TreeNode* Root = new TreeNode{PostOrder[PostEnd]};
	    if (PostStart == PostEnd)
	    {
		    return Root;
	    }

    	int SplitIndex = InStart;
	    for (int i = InStart; i <= InEnd; ++i)
	    {
		    if (InOrder[i] == PostOrder[PostEnd])
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

    	int LeftPostStart = PostStart;
    	int LeftPostEnd = PostStart + LeftInEnd - LeftInStart;
    	int RightPostStart = LeftPostEnd + 1;
    	int RightPostEnd = PostEnd - 1;

    	cout<< "PostOrderIndex: " << LeftPostStart << LeftPostEnd << RightPostStart << RightPostEnd << '\n';

    	Root->left = BuildTree_Impl(InOrder, LeftInStart, LeftInEnd, PostOrder, LeftPostStart, LeftPostEnd);
    	Root->right = BuildTree_Impl(InOrder, RightInStart, RightInEnd, PostOrder, RightPostStart, RightPostEnd);
    	return Root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
