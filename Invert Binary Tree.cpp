#include <iostream>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
 		if (root == NULL) {
			return root;
		} else {
			TreeNode *left = root->left;
			TreeNode *right = root->right;
			TreeNode *temp;

			invertTree(left);
			invertTree(right);

			temp = root->left;
			root->left = root->right;
			root->right = temp;
		}
    }
};

