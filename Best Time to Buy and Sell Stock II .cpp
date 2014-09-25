#include <iostream>
#include <vector>
#include <cstdio>

#define _CRT_SECURE_NO_WARNINGS

class Solution {
public:
	int maxProfit(std::vector<int> &prices) {
		int ret = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > prices[i - 1]) {
				ret += prices[i] - prices[i - 1];
			}
		}
		return ret;
	}
};

int main() {
	std::vector<int> a;
	int n;
	Solution s;
	/*while (std::cin >> n) {
		a.push_back(n);
	}*/
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	std::cout << s.maxProfit(a) << std::endl;

	return 0;
}