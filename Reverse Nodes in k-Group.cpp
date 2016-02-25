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
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *pivot = new ListNode(0);
		ListNode *ghead = head, *p, *q, *v, *gtail, *last;
		int count;
		pivot->next = head;
		last = pivot;

		if (k == 1) return head;
		
		while (true) {
			gtail = ghead;
			count = 0;
			while (gtail != NULL && count < k-1) {
				gtail = gtail->next;
				count++;
			}
			if (gtail != NULL) { // nead to reverse
				p = ghead; q = p->next; v = q->next;
				for (int i = 0; i < k-1; i++) {
					q->next = p; 
					p = q;
					q = v;
					if (q != NULL) v = v->next;
				}
				last->next = gtail;
				ghead->next = q;

				last = ghead;
				ghead = q;
			} else {
				break;
			}
		}
		pivot = pivot->next;
		return pivot;
    }
};
