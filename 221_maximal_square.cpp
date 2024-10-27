#include<iostream>
#include<vector>
#include<string>
using namespace std;



class Solution {
public:
    int dp[300][300];

    int max_sq(int i, int j, vector<vector<char>>& matrix) {
        if (i < 0 || j < 0 || matrix[i][j] == '0') return 0;
        if (dp[i][j]) return dp[i][j];

        return dp[i][j] = 1 + min(max_sq(i - 1, j, matrix), min(max_sq(i, j - 1, matrix), max_sq(i - 1, j - 1, matrix)));;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // dp[i][j] = max square ending at matrix[i][j]
        // its a square of size n if left tile, upper tile, and upper left tile is a square of size n - 1
        int ans = 0;
        // init 
        for (int i = 0; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            ans = max(dp[i][0], ans);
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            ans = max(dp[0][j], ans);
        } 

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                ans = max(ans, max_sq(i, j, matrix));
            }
        }
        return ans * ans;
    }
};

void main() {
    Solution S;
    vector<vector<char>> matrix({ {'0', '1'},{'1', '0'} });
    S.maximalSquare(matrix);
}