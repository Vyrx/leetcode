#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<bool>> dp; // true if visited before

    bool rec(string &s, string &p, int in_1, int in_2) {
        if (dp[in_1][in_2]) return false;

        dp[in_1][in_2] = true;

        if (in_1 >= s.size() || in_2 >= p.size()) {
            if (in_1 >= s.size() && in_2 >= p.size()) return true;
            else if (in_2 < p.size() && p[in_2] == '*') return rec(s, p, in_1, in_2 + 1);
            else return false;
        }

        if (p[in_2] == '?') {
            return rec(s, p, in_1 + 1, in_2 + 1);
        }
        else if (p[in_2] == '*') {
            for (int i = in_1; i <= s.size(); i++) {
                if (rec(s, p, i, in_2 + 1)) {
                    return true;
                }
            }
            return false;
        }
        else {
            if (s[in_1] == p[in_2])
                return rec(s, p, in_1 + 1, in_2 + 1);
            else return false;
        }
    }

    bool isMatch(string s, string p) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        dp = vector<vector<bool>>(s.size() + 1, vector<bool>(p.size() + 1, false));

        if (s.size() == 0) {
            for (auto& it : p) {
                if (it != '*')
                    return false;
            }
            return true;
        }

        return rec(s, p, 0, 0);

    }
};

void main() {
    Solution S;
    string s = "a";
    string p = "a*";
    cout << S.isMatch(s, p);
}