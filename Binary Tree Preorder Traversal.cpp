#include <iostream>
#include <vector>
#include <stack>
// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	std::vector<int> preorderTraversal(TreeNode *root) {
		std::stack<TreeNode*> st;
		std::vector<int> ret;
		TreeNode *p;
		st.push(root);
		while (!st.empty()) {
			p = st.top();
			st.pop();
			if (p == NULL) {
				continue;
			}
			if (p->left == NULL && p->right == NULL) {
				ret.push_back(p->val);
			}
			else {
				st.push(p->right);
				st.push(p->left);
				st.push(new TreeNode(p->val));
			}
		}
		return ret;
	}
};

int main() {
	TreeNode *p;
	std::vector<int> a;
	Solution s;
	p = new TreeNode(1);
	p->right = new TreeNode(2);
	p->right->left = new TreeNode(3);
	a = s.preorderTraversal(p);
	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << std::endl;
	}
	return 0;
}