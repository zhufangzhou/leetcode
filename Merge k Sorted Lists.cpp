#include <iostream>
#include <queue>

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
	struct node {
		int id;
		ListNode* p;
		node (int id, ListNode *p) : id(id), p(p) {

		}
		bool operator < (const struct node &a) const {
			return p->val > a.p->val;
		}
	};
	struct
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<node> q;
		int n = lists.size(), count = 0;
		ListNode *sorted = new ListNode(0);
		for (int i = 0; i < n; i++) {
			if (lists[i] != NULL) {
				node temp(i, lists[i]);
				q.push(temp);
				lists[i] = lists[i]->next;
			}
			if (lists[i] == NULL) count++;
		}
		ListNode *pp = sorted;
		while (!q.empty()) {
			node d = q.top();
			ListNode *p = d.p;
			int id = d.id;
			q.pop();

			pp->next = p;
            pp = pp->next;
			if (lists[id] != NULL) {
				node temp(id, lists[id]);
				q.push(temp);
				lists[id] = lists[id]->next;
				if (lists[id] == NULL) count++;
			}
		}
		sorted = sorted->next;
		return sorted;
    }
};
