// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem968.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// @lc code=start
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

    enum class ENodeState
    {
        None, 
        Valid,
        Camera
    };

    int minCameraCover(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        
        int CameraCount = 0;
        ENodeState RootState = GetNodeState(root, CameraCount);
        if (RootState == ENodeState::None)
        {
            CameraCount++;
        }
        return CameraCount;
    }

    ENodeState GetNodeState(TreeNode* Node, int& CameraCount) {
        if (!Node)
        {
            return ENodeState::Valid;
        }
        
        ENodeState LeftState = GetNodeState(Node->left, CameraCount);
        ENodeState RightState = GetNodeState(Node->right, CameraCount);

        if (LeftState == ENodeState::Valid && RightState == ENodeState::Valid)
        {
            return ENodeState::None;
        }
        else if (LeftState == ENodeState::None || RightState == ENodeState::None) // 要先判断这个条件，很重要！！！
        {
            CameraCount++;
            return ENodeState::Camera;
        }
        else
        {
            return ENodeState::Valid;
        }
    }
};
// @lc code=end

