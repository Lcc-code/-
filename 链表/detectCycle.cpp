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



