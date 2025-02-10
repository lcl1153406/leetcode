//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。 
//
// 
//
// 示例 1： 
//
// 
// 输入：root = [1,null,2,3] 
// 
//
// 输出：[1,2,3] 
//
// 解释： 
//
// 
//
// 示例 2： 
//
// 
// 输入：root = [1,2,3,4,5,null,8,null,null,6,7,9] 
// 
//
// 输出：[1,2,4,5,6,7,3,8,9] 
//
// 解释： 
//
// 
//
// 示例 3： 
//
// 
// 输入：root = [] 
// 
//
// 输出：[] 
//
// 示例 4： 
//
// 
// 输入：root = [1] 
// 
//
// 输出：[1] 
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
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？ 
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 1313 👎 0

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
    // 基于增加空指针的写法
    /*
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> Result;
        if (!root)
        {
            return Result;
        }
        stack<TreeNode*> Stack;
        Stack.push(root);
        while (!Stack.empty())
        {
            auto* Node = Stack.top();
            Stack.pop();
            if (Node)
            {
                if (Node->right)
                {
                    Stack.push(Node->right);
                }
                if (Node->left)
                {
                    Stack.push(Node->left);
                }
                Stack.push(Node);
                Stack.push(nullptr);
            }
            else
            {
                auto* RealNode = Stack.top();
                Stack.pop();
                Result.push_back(RealNode->val);
            }
        }
        return Result;
    }
    */

    using FItem = std::pair<TreeNode*, bool>;
    vector<int> preorderTraversal(TreeNode* root) {
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
                if (Node->left)
                {
                    Stack.emplace(Node->left, false);
                }
                Stack.emplace(Node, true);
            }
        }
        return Result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
