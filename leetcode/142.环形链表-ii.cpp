// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem142.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* Fast = head;
        ListNode* Slow = head;
        while (Fast != nullptr && Fast->next != nullptr)
        {
            Slow = Slow->next;
            Fast = Fast->next->next;
            if (Slow == Fast)
            {
                ListNode* Curr1 = head;
                ListNode* Curr2 = Slow;
                while (Curr1 != Curr2)
                {
                    Curr1 = Curr1->next;
                    Curr2 = Curr2->next;   
                }
                return Curr1;
            }
        }

        return nullptr;
    }
};
// @lc code=end

