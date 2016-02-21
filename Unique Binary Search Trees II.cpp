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
	vector<vector<TreeNode*> > cachedTrees;
	int globalLabel;
    vector<TreeNode*> generateTrees(int n) {
		cachedTrees.push_back(vector<TreeNode*>{});
		cachedTrees[0].push_back(NULL);
		if (n == 0) {
			vector<TreeNode*> ret;
			return ret;
		}

		for (int i = 1; i <= n; i++) {
			cachedTrees.push_back(vector<TreeNode*>{});
			for (int leftNum = 0; leftNum <= i-1; leftNum++) {
				int rightNum = i - 1 - leftNum;
				for (int left = 0; left < cachedTrees[leftNum].size(); left++) {
					for (int right = 0; right < cachedTrees[rightNum].size(); right++) {
						TreeNode *root = new TreeNode(0);
						root->left = cachedTrees[leftNum][left];
						root->right = cachedTrees[rightNum][right];
						cachedTrees[i].push_back(root);
					}
				}

			}
		}
		
		vector<TreeNode*> ret;
		for (int i = 0; i < cachedTrees[n].size(); i++) {
			globalLabel = 1;
			ret.push_back(traverse(cachedTrees[n][i]));
		}
		return ret;
    }

	TreeNode* traverse(TreeNode* root) {
		TreeNode *newRoot = new TreeNode(0);

		if (root->left) {
			newRoot->left = traverse(root->left);
		} 
		newRoot->val = globalLabel++;
		if (root->right) {
			newRoot->right = traverse(root->right);
		} 

		return newRoot;
	}
};
