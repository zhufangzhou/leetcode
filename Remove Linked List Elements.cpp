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
    ListNode* removeElements(ListNode* head, int val) {
		ListNode *p, *q;		        
		if (!head) return head;
		p = head;
		q = p->next;
		// remove non-head
		while (q != NULL) {
			if (q->val == val) {
				p->next = q->next;
				delete q;
				q = p->next;
			} else {
				p = p->next;
				q = p->next;
			}
		}
		if (head->val == val) {
			p = head;
			head = head->next;
			delete p;
		}
		return head;
    }
};
