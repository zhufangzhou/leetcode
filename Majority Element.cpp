#include <iostream>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		int cand, count = 0;
		for (int n : nums) {
			if (count == 0) {
				cand = n;
				count++;
			} else if (cand == n) {
				count++;
			} else {
				count--;
			}
		}
		return cand;
    }
};
