#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    // F > E
    // E > W
    // W > F
    // possible final score is -n ~ n

    long long get_dp(vector<vector<vector<long long>>> &dp, string &s, int n, int index, int point, char move) {
        if (index < 0) return 0;
        if (point > index + 1 || point < -(index + 1)) {
            if (point <= n && point >= -n) {
                assign_dp(dp, s, n, index, point, move, 0);
            }
            return 0;
        }
        
        switch (move) {
        case 'F':
            if (dp[index][point + n][0] != -1)
                return dp[index][point + n][0];
            break;
        case 'W':
            if (dp[index][point + n][1] != -1)
                return dp[index][point + n][1];
            break;
        case 'E':
            if (dp[index][point + n][2] != -1)
                return dp[index][point + n][2];
            break;
        }

        int point_change;
        if (move == s[index]) { // tie
            point_change = 0;
        }
        else if ((move == 'F' && s[index] == 'E') || (move == 'E' && s[index] == 'W') || (move == 'W' && s[index] == 'F')) { // win
            point_change = 1;
        }
        else point_change = -1;

        long long val = 0;

        if (move == 'F')
            val += get_dp(dp, s, n, index - 1, point - point_change, 'E') + get_dp(dp, s, n, index - 1, point - point_change, 'W');
        else if (move == 'E')
            val += get_dp(dp, s, n, index - 1, point - point_change, 'F') + get_dp(dp, s, n, index - 1, point - point_change, 'W');
        else
            val += get_dp(dp, s, n, index - 1, point - point_change, 'F') + get_dp(dp, s, n, index - 1, point - point_change, 'E');

        val %= 1000000007;

        assign_dp(dp, s, n, index, point, move, val);

        return val;
    }

    void assign_dp(vector<vector<vector<long long>>>& dp, string& s, int n, int index, int point, char move, int value) {
        switch (move) {
        case 'F':
            dp[index][point + n][0] = value;
            break;
        case 'W':
            dp[index][point + n][1] = value;
            break;
        case 'E':
            dp[index][point + n][2] = value;
            break;
        }
    }

    int countWinningSequences(string &s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        long long ans = 0;
        int n = s.size();
        // number of possible moves for:
        // [round index] 0 ~ n - 1 (size: n)
        // [point] -n ~ n (size: 2n + 1)
        // [last move played] F / W / E (size: 3)

        vector<vector<vector<long long>>> dp (n, vector<vector<long long>>( 2*n + 1, vector<long long>(3, -1)));
        // Assign DP for first index
        
        char win, tie, lose;
        if (s[0] == 'F') {
            win = 'W', tie = 'F', lose = 'E';
        }
        else if (s[0] == 'E') {
            win = 'F', tie = 'E', lose = 'W';
        }
        else {
            win = 'E', tie = 'W', lose = 'F';
        }
        dp[0] = vector<vector<long long>>(2 * n + 1, vector<long long>(3, 0));
        assign_dp(dp, s, n, 0, 1, win, 1);
        assign_dp(dp, s, n, 0, 0, tie, 1);
        assign_dp(dp, s, n, 0, -1, lose, 1);
        
        
        for (int i = 1; i <= n; i++) { // get all answer with positive points
            ans += get_dp(dp, s, n, n - 1, i, 'F');
            ans += get_dp(dp, s, n, n - 1, i, 'E');
            ans += get_dp(dp, s, n, n - 1, i, 'W');
        }

        return ans %= 1000000007;
    }
};

void main() {
    Solution Sol;
    string s = "FFF";
    cout << Sol.countWinningSequences(s);
}


