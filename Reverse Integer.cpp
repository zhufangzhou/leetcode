#include <iostream>

class Solution {
public:
	int reverse(int x) {
		int flag, ret = 0;
		if (x < 0) {
			flag = -1;
			x = -x;
		} else if (x > 0) {
			flag = 1;
		} else {
			return 0;
		}
		while (x > 0) {
			ret *= 10;
			ret += x % 10;
			x /= 10;
		}
		return flag*ret;
	}
};

int main() {
	Solution s;
	std::cout << s.reverse(-123) << std::endl;
	return 0;
}