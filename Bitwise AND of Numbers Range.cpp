#include <iostream>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
 		int u = m, v = n, digit = -1;
		for (int i = 0; i < 32; i++) {
			if ((u & 0x01) != (v & 0x01)) {
				digit = i;
			}
			u >>= 1;
			v >>= 1;
		}
		if (digit == -1) {
			return m;
		} else {
			return m & (~((1 << (digit+1))-1));
		}
    }
};

int main() {
	Solution s;
	std::cout << s.rangeBitwiseAnd(5, 7) << std::endl;
	return 0;
}
