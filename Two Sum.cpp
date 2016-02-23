#include <iostream>
#include <algorithm>

class Solution {
public:
	struct node {
		int val, idx;
		node(int val, int idx) : val(val), idx(idx) {

		}
		bool operator < (const node &a) {
			return val < a.val;
		}
	};
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<node> temp;
		int count = 0;
		for (int m : nums) {
			temp.push_back(node(m, count++));
		}
		sort(temp.begin(), temp.end());
		int n = temp.size();
		int l = 0, r = n-1;
		vector<int> ret;
		while (l < r) {
			int temp_sum = temp[l].val + temp[r].val;
			if (temp_sum == target) {
				ret.push_back(temp[l].idx);
				ret.push_back(temp[r].idx);
				return ret;
			}
			if (temp_sum >= target) {
				int last_val = temp[r].val;
				while (last_val == temp[r].val) r--;
			} else {
				int last_val = temp[l].val;
				while (last_val == temp[l].val) l++;
			}
		}
    }
};
