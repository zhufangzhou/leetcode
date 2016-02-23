#include <iostream>
#include <map>

class Solution {
public:
    int romanToInt(string s) { 
		int base[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string letter[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		map<string, int> m;
		for (int i = 0; i < 13; i++) {
			m[letter[i]] = base[i];
		}
		int ret = 0;
		for (int i = 0; i < s.size(); i++) {
			stringstream ss1, ss2;
			ss1 << s[i];
			string s1 = ss1.str();
			if (i < s.size()-1) {
				ss2 << s[i+1];
				string s2 = ss2.str();
				if (m[s1] < m[s2]) {
					ret += m[s1+s2];	
					i++;
				} else {
					ret += m[s1];
				}
			} else {
				ret += m[s1];
			}
		}
		return ret;
    }
};
