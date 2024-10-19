#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        stack<int> stack; // store index
        int cur_max = 0;

        for (int i = 0; i < s.size(); i++) {
            if (stack.empty() || s[i] == '(' || s[stack.top()] == ')') stack.push(i);
            else {
                s[stack.top()] = '0';
                s[i] = '0';
                stack.pop();
                if (stack.empty()) cur_max = i + 1;
                else cur_max = max(cur_max, i - stack.top());
            }
        }

        return cur_max;
    }
};