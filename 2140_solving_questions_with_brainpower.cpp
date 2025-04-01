#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int n;

    /*long long rec(vector<vector<int>>& questions, vector<long long> &dp, int i) {
        if (i >= n) return 0;
        if (dp[i]) return dp[i];
        return dp[i] = max(rec(questions, dp, i + 1), questions[i][0] + rec(questions, dp, i + questions[i][1] + 1));
    }*/

    long long mostPoints(vector<vector<int>>& questions) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        n = questions.size();
        vector<long long> dp(n + 1, 0);
        //return rec(questions, dp, 0);
        for (int i = n - 1; i >= 0; i--) {
            int nextInd = i + questions[i][1] + 1;
            long long pick = questions[i][0] + dp[nextInd < n ? nextInd : 0];
            long long notPick = dp[i + 1];
            dp[i] = max(pick, notPick);
        }
        return dp[0];
    }
};

void main() {
    Solution S;
    cout << "hi";

}