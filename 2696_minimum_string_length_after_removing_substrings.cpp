#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:

    int minLength(string &s) {
        stack<char> stack;
        int removed = 0;
        for (int i = 0; i < s.size(); i++) {
            if (stack.empty()) stack.push(s[i]);
            else {
                if ((s[i] == 'B' && stack.top() == 'A') || (s[i] == 'D' && stack.top() == 'C')) {
                    removed += 2;
                    stack.pop();
                }
                else {
                    stack.push(s[i]);
                }
            }
        }
        return s.size() - removed;
    }
};

void main() {
    Solution Sol;
    string s = "CCDAABBDCD";
    cout << Sol.minLength(s);
}