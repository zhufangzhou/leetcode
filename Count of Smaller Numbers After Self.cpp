#include <iostream>

// insertion sort version
/*
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
 		int n = nums.size();
		vector<int> sorted, count;
		sorted.resize(n);
		count.resize(n);
		
		for (int i = n-1; i >= 0; i--) {
			int j = n-1-i-1;
			while (j >= 0) {
				if (sorted[j] >= nums[i]) sorted[j+1] = sorted[j];
				else break;
				j--;
			}
			sorted[j+1] = nums[i];
			count[i] = j+1;
		}
		return count;
    }
};
*/

// binary search tree version
class Solution {
public:
    struct node {
        int val, count;
        node *left, *right;
        node(int val) : val(val), count(0), left(NULL), right(NULL) {

        }
    };
    int insertNode(node *root, int val, int buffer_count) {
        if (root->val < val) {
            if (root->right) {
                return insertNode(root->right, val, buffer_count + root->count + 1);
            }
            root->right = new node(val);
            buffer_count += root->count + 1;
        } else {
            root->count++;
            if (root->left) {
                return insertNode(root->left, val, buffer_count);
            }
            root->left = new node(val);
        }
        return buffer_count;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        if (n == 0) return ret;
        node *root = new node(nums[n-1]);
        ret[n-1] = 0;
        for (int i = n-2; i >= 0; i--) {
            int cnt = insertNode(root, nums[i], 0);
            ret[i] = cnt;
        }
        return ret;
    }
};
