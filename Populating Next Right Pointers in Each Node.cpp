#include <iostream>
#include <vector>
//Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		std::vector<TreeLinkNode*> v;
		std::vector<int> depth;
		TreeLinkNode *cNode;
		int idx = 0;
		if (root == NULL) return;
		
		v.push_back(root);
		depth.push_back(1);
		while (idx < v.size()) {
			cNode = v[idx];
			if (cNode->left != NULL) {
				v.push_back(cNode->left);
				depth.push_back(depth[idx] + 1);
			}
			if (cNode->right != NULL) {
				v.push_back(cNode->right);
				depth.push_back(depth[idx] + 1);
			}
			idx++;
		}
		for (int i = 1; i < v.size(); i++) {
			if (depth[i - 1] == depth[i]) {
				v[i - 1]->next = v[i];
			}
		}
	}
};

int main() {
	TreeLinkNode *root = NULL;
	Solution s;
	root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	s.connect(root);
}