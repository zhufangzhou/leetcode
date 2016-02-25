#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > m;
        for (string s : strs) {
            int alpha[26];
            memset(alpha, 0, sizeof(int)*26);
            for (char c : s) {
                alpha[c-'a']++;
            }
            string temp = "";
            for (int i = 0; i < 26; i++) {
                temp += string(alpha[i], 'a'+i);
            }
            if (m.find(temp) == m.end()) {
                m[temp] = vector<string>();
            }
            m[temp].push_back(s);

        }
        vector<vector<string> > ret;
        for (auto it = m.begin(); it != m.end(); ++it) {
			sort(it->second.begin(), it->second.end());
            ret.push_back(it->second);
        }
        return ret;
    }
};

int main() {
	Solution s;
	vector<string> strs = {
		"rat", "atr"
	};
	s.groupAnagrams(strs);
	return 0;
}
