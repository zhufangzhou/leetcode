#include <iostream>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		int cand[2], count[2], size = 0;        
		for (int n : nums) {
			bool contain = false, idx;
			for (int i = 0; i < size; i++) {
				if (cand[i] == n) {
					idx = i;
					contain = true;
					break;
				}
			}
			if (contain) {
				count[idx] += 1;	
			} else {
				if (size < 2) {
					cand[size] = n;
					count[size] = 1;
					size++;
				} else {
					bool delete_first = false, delete_second = false;
					if (count[0] == 1) delete_first = true;
					if (count[1] == 1) delete_second = true;
					if (delete_first) {
						cand[0] = cand[1];
						count[0] = count[1];
						size--;
					}
					if (delete_second) {
						size--;
					}
					for (int i = 0; i < size; i++) count[i]--;
				}
			}
		}

		count[0] = count[1] = 0;
		for (int n : nums) {
			for (int i = 0; i < size; i++) {
				if (n == cand[i]) {
					count[i]++;
				}
			}
		}
		vector<int> ret;
		for (int i = 0; i < size; i++) {
			if (count[i] > nums.size() / 3) {
				ret.push_back(cand[i]);
			}
		}
		return ret;
    }
};
