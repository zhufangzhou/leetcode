#include <iostream>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	int maxDepth(TreeNode *root) {
		int maxLeft, maxRight;
		if (root == NULL) {
			return 0;
		}
		maxLeft = maxDepth(root->left);
		maxRight = maxDepth(root->right);
		if (maxLeft > maxRight) {
			return maxLeft + 1;
		}
		else {
			return maxRight + 1;
		}
	}
};