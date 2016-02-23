#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
		int bufferNum = -1;
		stack<int> numStack, tempNumStack;
		stack<char> sigStack, tempSigStack;
		for (char c : s) {
			if (c >= '0' && c <= '9') {
				if (bufferNum == -1) {
					bufferNum = 0;
				}
				bufferNum = bufferNum * 10 + c - '0';
			} else if (c == '+' || c == '-' || c == '(' || c == ')') {
				if (bufferNum != -1) {
					numStack.push(bufferNum);
					bufferNum = -1;
				}
				if (c == ')') {
					tempNumStack.push(numStack.top());
					numStack.pop();
					while (!numStack.empty() && sigStack.top() != '(') {
						tempNumStack.push(numStack.top());	
						numStack.pop();
						tempSigStack.push(sigStack.top());
						sigStack.pop();
					}
					int leftNum = tempNumStack.top();
					tempNumStack.pop();
					while(!tempNumStack.empty()) {
						int rightNum = tempNumStack.top();
						tempNumStack.pop();
						char curSig = tempSigStack.top();
						tempSigStack.pop();
						if (curSig == '+') {
							leftNum = leftNum + rightNum;
						} else if (curSig == '-') {
							leftNum = leftNum - rightNum;
						}

					}
					numStack.push(leftNum);
					if (sigStack.top() == '(') {
						sigStack.pop();
					}
				} else {
					sigStack.push(c);
				}
			}
		}
		if (bufferNum != -1) numStack.push(bufferNum);

		tempNumStack.push(numStack.top());
		numStack.pop();
		while (!numStack.empty()) {
			tempNumStack.push(numStack.top());	
			numStack.pop();
			tempSigStack.push(sigStack.top());
			sigStack.pop();
		}
		int leftNum = tempNumStack.top();
		tempNumStack.pop();
		while(!tempNumStack.empty()) {
			int rightNum = tempNumStack.top();
			tempNumStack.pop();
			char curSig = tempSigStack.top();
			tempSigStack.pop();
			if (curSig == '+') {
				leftNum = leftNum + rightNum;
			} else if (curSig == '-') {
				leftNum = leftNum - rightNum;
			}

		}

		cout << leftNum << endl;
		return leftNum;
    }
};


int main() {
	Solution s;
	s.calculate("1+3-(5-2)");
	return 0;
}
