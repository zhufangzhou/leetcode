#include <iostream>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *sorted, *p;
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        } else if (l1->val < l2->val) {
            sorted = l1; l1 = l1->next;
        } else {
            sorted = l2; l2 = l2->next;
        }
        p = sorted;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1; l1 = l1->next;
            } else {
                p->next = l2; l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 == NULL) {
            p->next = l2;
        } else {
            p->next = l1;
        }
        return sorted;
    }
};
