#include <iostream>

class Solution {
public:
	bool canJump(int A[], int n) {
		int maxStep = 1;
		for (int i = 0; i < n; i++) {
			if (i + 1 > maxStep) 
				return false;
			if (maxStep < A[i] + i + 1) {
				maxStep = A[i] + i + 1;
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	//int A[] = { 2, 3, 1, 4, 4 };
	int A[] = { 3, 2, 1, 0, 4 };
	std::cout << s.canJump(A, 5) << std::endl;
}