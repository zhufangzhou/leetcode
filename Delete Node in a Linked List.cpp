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
    void deleteNode(ListNode* node) {
 		ListNode *p, *q;       
		p = node;
		q = node->next;
		if (q != NULL) {
			p->val = q->val;
			p->next = q->next;
		}
    }
};
