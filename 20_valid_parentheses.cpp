#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		stack<char> stack;
		for (char c : s) {
			if (c == ')') {
				if (stack.empty() || stack.top() != '(') return false;
				stack.pop();
			}
			else if (c == ']') {
				if (stack.empty() || stack.top() != '[') return false;
				stack.pop();

			}
			else if (c == '}') {
				if (stack.empty() || stack.top() != '{') return false;
				stack.pop();

			}
			else {
				stack.push(c);
			}
		}
		return stack.empty();
	}
};