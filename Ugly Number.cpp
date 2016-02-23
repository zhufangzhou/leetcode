#include <iostream>

class Solution {
public:
    bool isUgly(int num) {
		int n = num, factor[3] = {2, 3, 5};
		if (n < 1) return false;
		for (int i = 0; i < 3; i++) {
			while (n % factor[i] == 0) n /= factor[i];
		}
		return n == 1;
    }
};
