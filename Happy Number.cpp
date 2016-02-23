#include <iostream>
#include <set>

class Solution {
public:
    bool isHappy(int n) {
		set<int> s;  
		s.insert(n);
		while (true) {
			if (n == 1) return true;
			else {
				int m = n;
				n = 0;
				while (m != 0) {
					n += (m%10) * (m%10);
					m /= 10;
				}
				if (s.find(n) != s.end()) return false;
				else s.insert(n);
			}
		}
    }
};
