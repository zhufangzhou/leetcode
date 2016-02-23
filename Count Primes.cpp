#include <iostream>

class Solution {
public:
    int countPrimes(int n) {
		bool* prime = new bool[n+1];
		for (int i = 0; i <= n; i++) prime[i] = true;
		if (n < 2) return 0;
		else {
			int count = 0;
			for (int i = 3; i < n; i += 2) {
				if (prime[i] == true) {
					count++;
					for (int j = 2; i*j <= n; j++) prime[i*j] = false;
				} else {
					continue;
				}
			}
			return count+1;
		}
    }
};
