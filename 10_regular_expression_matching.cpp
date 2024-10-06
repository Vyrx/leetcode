#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    bool recur(string s, string p, int i_s, int i_p) {
        if (i_s == s.size() && i_p == p.size()) return true;
        if (i_p >= p.size() && i_s < s.size()) return false; // when p is finished but not yet s

        if (dp[i_s][i_p] != -1) return dp[i_s][i_p];

        if (p[i_p] != '.') {
            if (i_p >= p.size() - 1 || p[i_p + 1] != '*') { // if last index / next chara is not *
                if (i_s >= s.size() || p[i_p] != s[i_s]) {
                    dp[i_s][i_p] = 0;
                    return false;
                }
                else return recur(s, p, i_s + 1, i_p + 1);
            }
            else { // when it is followed by *
                // check all possibilities, return true if one of them return true
                if (recur(s, p, i_s, i_p + 2)) {
                    dp[i_s][i_p] = 1;
                    return true; // when x* is ignored
                }
                if (i_s >= s.size()) {
                    dp[i_s][i_p] = 0;
                    return false;
                }
                for (int i = i_s; i < s.size(); i++) {
                    if (s[i] != p[i_p]) break;
                    else if (recur(s, p, i + 1, i_p + 2)) {
                        dp[i_s][i_p] = 1;
                        return true;
                    }
                }
                dp[i_s][i_p] = 0;
                return false;
            }
        }
        else { // p[i_p] == '.'
            if (i_p >= p.size() - 1 || p[i_p + 1] != '*') { // if last index / next chara is not *
                if (i_s >= s.size()) {
                    dp[i_s][i_p] = 0;
                    return false;
                }
                return recur(s, p, i_s + 1, i_p + 1);
            }
            else { // .* condition
                if (recur(s, p, i_s, i_p + 2)) {
                    dp[i_s][i_p] = 1;
                    return true;
                }
                if (i_s >= s.size()) {
                    dp[i_s][i_p] = 0;
                    return false;
                }
                for (int i = i_s; i < s.size(); i++) {
                    if (recur(s, p, i + 1, i_p + 2)) {
                        dp[i_s][i_p] = 1;
                        return true;
                    }
                }
                dp[i_s][i_p] = 0;
                return false;
            }
        }
    }

    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
        return recur(s, p, 0, 0);
    }
};

void main() {
    Solution sol;
    string s = "a", p = "ab*";
    cout << sol.isMatch(s, p);
}