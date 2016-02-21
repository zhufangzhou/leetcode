#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	vector<vector<TreeNode*> > cachedTrees;
	int globalLabel;

    vector<int> diffWaysToCompute(string input) {
 		int bufferNumber = 0;       
		vector<int> inputItems;	
		vector<TreeNode*> empty;
		for (char c : input) {
			if (c >= '0' && c <= '9') {
				bufferNumber = bufferNumber * 10 + c - '0';
			} else if (c == '+') {
				inputItems.push_back(bufferNumber);	
				bufferNumber = 0;
				inputItems.push_back(-1);	
			} else if (c == '-') {
				inputItems.push_back(bufferNumber);	
				bufferNumber = 0;
				inputItems.push_back(-2);	
			} else if (c == '*') {
				inputItems.push_back(bufferNumber);	
				bufferNumber = 0;
				inputItems.push_back(-3);	
			}
		}
		inputItems.push_back(bufferNumber);

		cachedTrees.push_back(vector<TreeNode*>());
		cachedTrees[0].push_back(NULL);
		int n = inputItems.size();

		if (n == 1) {
			vector<int> ret;
			ret.push_back(inputItems[0]);
			return ret;
		}

		vector<TreeNode*> a;
		a.push_back(new TreeNode(0));
		cachedTrees.push_back(a);
		
		for (int i = 2; i <= n; i++) {
			cachedTrees.push_back(vector<TreeNode*>());
			for (int leftNum = 1; leftNum <= i-1; leftNum+=2) {
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
			cout << i << ' ' << cachedTrees[i].size() << endl;
		}

		vector<int> ret;
		for (int i = 0; i < cachedTrees[n].size(); i++) {
			globalLabel = 0;
			TreeNode *temp = traverse(cachedTrees[n][i], inputItems);
			int val = computeTree(temp);
			ret.push_back(val);
		}
			
		return ret;
    }

	bool checkTree(TreeNode* root) {
		if (root->val >= 0) {
			if (root->left != NULL || root->right != NULL) {
				return false;
			} else {
				return true;
			}
		} else {
			return checkTree(root->left) && checkTree(root->right);
		}
	}

	int computeTree(TreeNode* root) {
		int left, right;
		if (root->left->val < 0) {
			left = computeTree(root->left);
		} else {
			left = root->left->val;
		}
		if (root->right->val < 0) {
			right = computeTree(root->right);
		} else {
			right = root->right->val;
		}
		if (root->val == -1) {
			return left + right;
		} else if (root->val == -2) {
			return left - right;
		} else {
			return left * right;
		}
	}

	TreeNode* traverse(TreeNode* root, vector<int> &inputItems) {
		TreeNode *newRoot = new TreeNode(0);
		if (root->left) {
			newRoot->left = traverse(root->left, inputItems);
		} 
		newRoot->val = inputItems[globalLabel++];
		if (root->right) {
			newRoot->right = traverse(root->right, inputItems);
		}

		return newRoot;
	}
};

int main() {
	Solution s;
	vector<int> a = s.diffWaysToCompute("1-2+3*4-5*6-7+8*9");
	return 0;
}
