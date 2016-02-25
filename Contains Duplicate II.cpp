#include <iostream>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		int i, j, n = nums.size();
		i = j = 0;
		if (k == 0) return false;
		while (j < n) {
			if (j - i > k) {
				m[nums[i]]--;
				i++;
			}

			m[nums[j]]++;
			if (m[nums[j]] > 1) return true;
			j++;
		}
		return false;
    }
};
