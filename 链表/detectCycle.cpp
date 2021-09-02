/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "ListNode.hpp"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
                ListNode *slow = head;
        ListNode *fast = head;
        ListNode *meet = NULL;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (!fast)
            {
                return NULL;
            }
            fast = fast->next;
            if (fast == slow)
            {
                meet = fast;
                break;
            }
        }
        if (!meet)
            return NULL;
        while (head && meet)
        {
            if (head == meet)
            {
                return head;
            }
            head = head->next;
            meet = meet->next;
        }
        return NULL;


    
  

    }

    ListNode *detectCycle_Set(ListNode *head)
    {
        std::set<ListNode *> Set;
        while (head)
        {
            if (Set.find(head) != Set.end())
            {
                return head;
            }
            Set.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};



