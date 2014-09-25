#include <iostream>

class Solution {
public:
	int numTrees(int n) {
		int *counts, ret;
		counts = new int[n+1];
		counts[0] = 1;
		for (int i = 1; i <= n; i++) {
			counts[i] = 0;
			for (int j = 1; j <= i; j++) {
				counts[i] += counts[j-1] * counts[i - j];
			}
		}
		ret = counts[n];
		delete[] counts;
		return ret;
	}
};

int main() {
	Solution s;
	std::cout << s.numTrees(3) << std::endl;
}