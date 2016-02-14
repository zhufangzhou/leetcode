#include <iostream>
class Solution {
public:
	int cache[100000];

    int climbStairs(int n) {
		for (int i = 0; i < 100000; i++) cache[i] = -1;		
		return solve(n);
    }
	int solve(int n) {
 		if (n == 1) {
			return 1;
		} else if (n == 2) {
			return 2;
		} else if (cache[n] != -1) {
			return cache[n];
		} else {
			cache[n] = solve(n-1) + solve(n-2);
			return cache[n];
		}

	}
};

