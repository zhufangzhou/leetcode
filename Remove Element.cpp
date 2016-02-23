#include <iostream>
#include <algorithm>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int fillIndex = 0;
		for (int n : nums) {
			if (n != val) {
				nums[fillIndex++] = n;
			}
		}
		return fillIndex;
    }
};
