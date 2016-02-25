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
    ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		} else {
			ListNode *p = head, *q = head->next, *last;		
			p->next = q->next;
			q->next = p;
			head = q;

			p = head->next->next;
			last = head->next;
			while (p != NULL && p->next != NULL) {
				q = p->next;
				p->next = q->next;
				q->next = p;
				last->next = q;

				p = q->next->next;
				last = q->next;
			}
			return head;
		}
    }
};
