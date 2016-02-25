#include <iostream>
#include <queue>
#include <set>
using namespace std;

/*
class Solution {
public:
    int nthUglyNumber(int n) {
		priority_queue<long long,vector<long long>,greater<long long> >q;  
		set<long long> s;
       	q.push(1);  
		s.insert(1);

		long long m;
		for (int i = 0; i < n; i++) {
			m = q.top();
			q.pop();
			cout << m << endl;
			if (m*2 > 0 && s.find(m*2) == s.end()) {
				q.push(m*2);
				s.insert(m*2);
			}
			if (m*3 > 0 && s.find(m*3) == s.end()) {
				q.push(m*3);
				s.insert(m*3);
			}
			if (m*5 > 0 && s.find(m*5) == s.end()) {
				q.push(m*5);
				s.insert(m*5);
			}
		}
		return int(m);
    }
};
*/
class Solution {
public:
	int nthUglyNumber(int n) {
		int a = 0, b = 0, c = 0, ugly[n];
		int m = 1;
		ugly[0] = 1;
		for (int i = 1; i < n; i++) {
			m = min(ugly[a]*2, min(ugly[b]*3, ugly[c]*5));
			ugly[i] = m;
			if (m == ugly[a]*2) a++;
			if (m == ugly[b]*3) b++;
			if (m == ugly[c]*5) c++;
		}
		return m;

	}
};

int main() {
	Solution s;
	s.nthUglyNumber(1600);

	return 0;
}
