#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // ob_count = current # of '('
    // count -> +1 when ( is added, -1 when ) is added

    void recur(vector<string> &ans, string s, int n, int ob_count, int count) {
        if (count < 0 || ob_count > n) return;

        if (ob_count == n && count == 0) {
            ans.push_back(s);
            return;
        }

        recur(ans, s + '(', n, ob_count + 1, count + 1);
        recur(ans, s + ')', n, ob_count, count - 1);
    }

    vector<string> generateParenthesis(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<string> ans;
        recur(ans, "(", n, 1, 1);

        return ans;
    }
};