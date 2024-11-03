#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if (s.size() != goal.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            if (mismatch(s.begin() + i, s.end(), goal.begin()).first == s.end()) { // s[i] until end is a prefix of goal
                if (s.substr(0, i) == goal.substr(goal.size() - i, i)) return true;
            }
        }
        return false;
    }
};