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
			} else if (c == '+' || c == '-' || c == '*' || c == '/') {
				if (bufferNum != -1) {
					// deal with * and /
					if (!sigStack.empty() && (sigStack.top() == '*' || sigStack.top() == '/')) {
						char curSig = sigStack.top();
						sigStack.pop();

						int leftNum = numStack.top();
						numStack.pop();
						if (curSig == '*') {
							numStack.push(leftNum * bufferNum);
						} else {
							numStack.push(leftNum / bufferNum);
						}
					} else {
						numStack.push(bufferNum);
					}

					bufferNum = -1;
				}
				sigStack.push(c);
			}
		}
		if (!sigStack.empty() && (sigStack.top() == '*' || sigStack.top() == '/')) {
			char curSig = sigStack.top();
			sigStack.pop();

			int leftNum = numStack.top();
			numStack.pop();
			if (curSig == '*') {
				numStack.push(leftNum * bufferNum);
			} else {
				numStack.push(1.0 * leftNum / bufferNum);
			}
		} else {
			numStack.push(bufferNum);
		}

		// deal with + and -
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
		cout << int(leftNum) << endl;
		return leftNum;
    }
};

int main() {
	Solution s;
	s.calculate("14/3*2");
	return 0;
}
