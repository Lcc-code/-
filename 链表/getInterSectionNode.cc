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
    // Set 时间 nlogn, 空间logn
    ListNode *getIntersectionNode_with_set(ListNode *headA, ListNode *headB)
    {
        
        std::set<ListNode *> Set;
        while (headA)
        {
            Set.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (Set.find(headB) != Set.end())
                return headB;
            headB = headB->next;
        }
        return NULL;

    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_list_A = get_list_length(headA);
        int len_list_B = get_list_length(headB);
        if (len_list_A > len_list_B)
            headA = forward_long_list(len_list_A, len_list_B, headA);
        else
            headB = forward_long_list(len_list_B, len_list_A, headB);
        
        while (headA && headB)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;

    }

private:
    int get_list_length(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len ++;
            head = head->next;
        }
        return len;
    }
    ListNode *forward_long_list(int long_len, int short_len, ListNode *head)
    {
        int delta = long_len - short_len;
        while (head && delta)
        {
            head = head->next;
            delta --;
        }
        return head;
    }
};

    
};