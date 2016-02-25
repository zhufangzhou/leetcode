#include <iostream>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) { 
		set<int> ss;
		for (int n : nums) {
			if (ss.find(n) != ss.end()) {
				return true;
			}
			ss.insert(n);
		}
		return false;
    }
};
