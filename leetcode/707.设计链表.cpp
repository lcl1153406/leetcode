// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem707.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */


// @lc code=start

// 单向链表
/*
class MyLinkedList {

    struct ListNode
    {
        int val = 0;
        ListNode* next = nullptr;

        ListNode() = default;
        ListNode(int InVal) : val(InVal){} 
    };

public:
    MyLinkedList() {
        DummyNode = new ListNode();
    }
    
    int get(int index) {
        if (index < 0 || index >= Size)
        {
            return -1;
        }
        
        ListNode* Current = DummyNode->next;
        while (index)
        {
            Current = Current->next;
            index--;
        }
        
        return Current->val;
    }
    
    void addAtHead(int val) {
        ListNode* NewNode = new ListNode(val);
        ListNode* TempNode = DummyNode->next;
        DummyNode->next = NewNode;
        NewNode->next = TempNode;
        Size++;
    }
    
    void addAtTail(int val) {
        ListNode* NewNode = new ListNode(val);
        ListNode* Current = DummyNode;
        while (Current->next)
        {
            Current = Current->next;
        }
        Current->next = NewNode;
        Size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > Size)
        {
            return;
        }
        
        ListNode* Current = DummyNode;
        while (index)
        {
            Current = Current->next;
            index--;
        }

        ListNode* NewNode = new ListNode(val);
        ListNode* NextNode = Current->next;
        Current->next = NewNode;
        NewNode->next = NextNode;
        Size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= Size)
        {
            return;
        }
        
        ListNode* Current = DummyNode;
        while (index)
        {
            Current = Current->next;
            index--;
        }
        ListNode* NextNode = Current->next;
        Current->next = NextNode->next;
        delete NextNode;
        Size--;
    }

    void printList() {
        ListNode* current = DummyNode->next;
        cout << "List: ";
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    ListNode* DummyNode = nullptr;
    int Size = 0;
};
*/

// 双向链表

class MyLinkedList {

    struct DLinkListNode
    {
        int val = 0;
        DLinkListNode* next = nullptr;
        DLinkListNode* prev = nullptr;
    };

public:
    MyLinkedList() {
        DummyNode = new DLinkListNode();
        DummyNode->next = DummyNode;
        DummyNode->prev = DummyNode;
    }
    
    int get(int index) {
        if (index < 0 || index >= Size)
        {
            return -1;
        }
        
        int Mid = Size / 2;
        if (index <= Mid)
        {
            DLinkListNode* Current = DummyNode->next;
            while (index)
            {
                Current = Current->next;
                index--;
            }
            return Current->val;
        }
        else
        {
            DLinkListNode* Current = DummyNode->prev;
            int TempCount = Size - index - 1;
            while (TempCount)
            {
                Current = Current->prev;
                TempCount--;
            }
            return Current->val;
        }
    }
    
    void addAtHead(int val) {
        DLinkListNode* NewNode = new DLinkListNode(val);
        DLinkListNode* NextNode = DummyNode->next;
        DummyNode->next = NewNode;
        NewNode->next = NextNode;
        NewNode->prev = DummyNode;
        NextNode->prev = NewNode;
        Size++;
    }
    
    void addAtTail(int val) {
        DLinkListNode* NewNode = new DLinkListNode(val);
        DLinkListNode* PrevNode = DummyNode->prev;
        DummyNode->prev = NewNode;
        NewNode->prev = PrevNode;
        NewNode->next = DummyNode;
        PrevNode->next = NewNode;
        Size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > Size)
        {
            return;
        }
        
        int Mid = Size / 2;
        if (index <= Mid)
        {
            DLinkListNode* Current = DummyNode;
            while (index)
            {
                Current = Current->next;
                index--;
            }
            DLinkListNode* NewNode = new DLinkListNode(val);
            DLinkListNode* NextNode = Current->next;
            Current->next = NewNode;
            NewNode->next = NextNode;
            NewNode->prev = Current;
            NextNode->prev = NewNode;
            Size++;
        }
        else
        {
            DLinkListNode* Current = DummyNode;
            int TempCount = Size - index;
            while (TempCount)
            {
                Current = Current->prev;
                TempCount--;
            }
            DLinkListNode* NewNode = new DLinkListNode(val);
            DLinkListNode* PrevNode = Current->prev;
            Current->prev = NewNode;
            NewNode->prev = PrevNode;
            NewNode->next = Current;
            PrevNode->next = NewNode;
            Size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= Size)
        {
            return;
        }
        int Mid = Size / 2;
        if (index <= Mid)
        {
            DLinkListNode* Current = DummyNode;
            while (index)
            {
                Current = Current->next;
                index--;
            }
            DLinkListNode* RemoveNode = Current->next;
            Current->next = RemoveNode->next;  
            RemoveNode->next->prev = Current;
            delete RemoveNode;
            Size--;
        }
        else
        {
            DLinkListNode* Current = DummyNode;
            int TempCount = Size - index - 1;
            while (TempCount)
            {
                Current = Current->prev;
                TempCount--;
            }
            DLinkListNode* RemoveNode = Current->prev;
            Current->prev = RemoveNode->prev;
            RemoveNode->prev->next = Current;
            delete RemoveNode;
            Size--;
        }
    }

private:
    DLinkListNode* DummyNode = nullptr;
    int Size = 0;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

