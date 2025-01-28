/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */


// Definition for singly-linked list.
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

    // 非递归版本
    // ListNode* reverseList(ListNode* head) {        
    //     ListNode* Prev = nullptr;
    //     ListNode* Current = head;
    //     while (Current)
    //     {
    //         ListNode* Next = Current->next;
    //         Current->next = Prev;
    //         Prev = Current;
    //         Current = Next;
    //     }
    //     return Prev;
    // }

    // 递归版本
    ListNode* reverseList(ListNode* head) {        
        if (!head || !head->next)
        {
            return head;
        }
        
        ListNode* LastNode = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return LastNode;
    }
};
// @lc code=end

