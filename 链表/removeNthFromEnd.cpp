// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre = new ListNode(0, head);
        ListNode *fast = pre;
        ListNode *low = pre;
        int i = n + 1;
        while (fast)
        {
            fast = fast->next;
            i--;
            if (i == 0)
                break;
        }
        if (i != 0)
            return nullptr;
        while (fast)
        {
            low = low->next;
            fast = fast->next;
        }
        low->next = low->next->next;
        return pre->next;
    }
};