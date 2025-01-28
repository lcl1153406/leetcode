// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem19.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode* DummyNode = new ListNode();
    //     DummyNode->next = head;
    //     int Size = 0;
    //     ListNode* Current = DummyNode->next;
    //     while (Current)
    //     {
    //         Size++;
    //         Current = Current->next;
    //     }
    //     int TempIndex = Size - n;
    //     if (TempIndex < 0)
    //     {
    //         return head;
    //     }
    //     Current = DummyNode;
    //     while (TempIndex)
    //     {
    //         Current = Current->next;
    //         TempIndex--;
    //     }
    //     ListNode* RemoveNode = Current->next;
    //     Current->next = RemoveNode->next;
    //     delete RemoveNode;
    //     return DummyNode->next;
    // }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* DummyNode = new ListNode();
        DummyNode->next = head;
        
        ListNode* FastNode = DummyNode;
        ListNode* SlowNode = DummyNode;
        int TempCount = n + 1;
        while (TempCount && FastNode)
        {
            FastNode = FastNode->next;
            TempCount--;
        }
        
        while (FastNode)
        {
            FastNode = FastNode->next;
            SlowNode = SlowNode->next;
        }
        
        ListNode* RemoveNode = SlowNode->next;
        SlowNode->next = RemoveNode->next;
        delete RemoveNode;
        return DummyNode->next;
    }
};
// @lc code=end

