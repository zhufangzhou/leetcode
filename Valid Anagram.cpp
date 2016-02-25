#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		if (s.size() != t.size()) {
			return false;
		} else if (s == t) {
			return true;
		} else {
			int sc[26], tc[26];
			for (int i = 0; i < 26; i++) sc[i] = tc[i] = 0;
			for (char c : s) sc[c-'a']++;
			for (char c : t) tc[c-'a']++;
			for (int i = 0; i < 26; i++) {
				if (sc[i] != tc[i]) return false;
			}
			return true;
		}
    }
};

int main() {
	Solution s;
	s.isAnagram("abc", "bca");
	return 0;
}
