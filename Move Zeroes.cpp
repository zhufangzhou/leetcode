#include <iostream>
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int fillIndex = 0;        
		for (int n : nums) {
			if (n != 0) {
				nums[fillIndex++] = n;
			}
		}
		for (int i = fillIndex; i < nums.size(); i++) {
			nums[i] = 0;
		}
    }
};
