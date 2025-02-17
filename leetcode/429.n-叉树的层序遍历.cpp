/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> Result;
        if (!root)
        {
            return Result;
        }
        
        queue<Node*> Queue;
        Queue.push(root);
        while (!Queue.empty())
        {
            int Size = Queue.size();
            vector<int> TempValues;
            for (int i = 0; i < Size; i++)
            {
                auto* Cur = Queue.front();
                Queue.pop();
                TempValues.push_back(Cur->val);

                for (auto* ChildNode: Cur->children)
                {
                    if (ChildNode)
                    {
                        Queue.push(ChildNode);
                    }
                }
            }
            Result.push_back(TempValues);
        }
        return Result;
    }
};
// @lc code=end

