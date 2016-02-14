#include <iostream>
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       	int x=0; 
		vector<int> ret(2, 0);
		for (int n : nums) {
			x ^= n;
		}
		int last = x & (~(x-1));
		for (int n : nums) {
			if ((last & n) == 0) {
				ret[0] ^= n;
			} else {
				ret[1] ^= n;
			}
		}
		return ret;
    }
};

