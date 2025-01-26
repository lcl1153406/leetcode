// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem203.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */



// @lc code=start

class Solution {
public:
    // ListNode* removeElements(ListNode* head, int val) {
    //     ListNode* Guard = new ListNode(0, head);
    //     ListNode* Current = Guard;
    //     while (Current && Current->next)
    //     {
    //         if (Current->next->val == val)
    //         {
    //             ListNode* TempNext = Current->next;
    //             Current->next = Current->next->next;
    //             delete TempNext;
    //         }
    //         else
    //         {
    //             Current = Current->next;
    //         }
    //     }
    //     head = Guard->next;
    //     delete Guard;
    //     return head;
    // }

    // 递归方式
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
        {
            return nullptr;
        }
        
        if (head->val == val)
        {
            ListNode* NewHead = removeElements(head->next, val);
            delete head;
            return NewHead;
        }
        else
        {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};
// @lc code=end

