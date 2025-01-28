// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem24.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    // 递归写法
    // ListNode* swapPairs(ListNode* head) {
    //     if (!head || !head->next)
    //     {
    //         return head;
    //     }
        
    //     ListNode* SecondNode = head->next;
    //     ListNode* SwapNode = swapPairs(SecondNode->next);
    //     SecondNode->next = head;
    //     head->next = SwapNode;
    //     return SecondNode;
    // }

    // 非递归写法
    ListNode* swapPairs(ListNode* head) {
        ListNode* DummyNode = new ListNode();
        DummyNode->next = head;
        ListNode* Current = DummyNode;
        while (Current->next && Current->next->next)
        {
            ListNode* NextNode = Current->next;
            ListNode* Next2Node = NextNode->next;
            ListNode* Next3Node = Next2Node->next;
            Current->next = Next2Node;
            Next2Node->next = NextNode;
            NextNode->next = Next3Node;
            
            Current = Current->next->next;
        }
        return DummyNode->next;
    }
};
// @lc code=end

