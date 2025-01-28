/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* Slow = head;
        ListNode* Fast = head;
        while (Fast && Fast->next)
        {
            Slow = Slow->next;
            Fast = Fast->next->next;
            if (Slow == Fast)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

