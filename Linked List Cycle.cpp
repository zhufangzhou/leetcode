#include <iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* p = head;
		while (p != NULL) {
			if (p->val == 0x5f5f5f5f) {
				return true;
			}
			p->val = 0x5f5f5f5f;
			p = p->next;
		}
		return false;
	}
};