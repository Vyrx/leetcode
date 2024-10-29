#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int m; int n;
    int rec(int i, int j, int prev, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j >= n || grid[i][j] <= prev) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = 1 + max(rec(i - 1, j + 1, grid[i][j], grid), max(rec(i, j + 1, grid[i][j], grid), rec(i + 1, j + 1, grid[i][j], grid)));
    }

    int maxMoves(vector<vector<int>>& grid) {
 
        m = grid.size(); n = grid[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, -1));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, rec(i, 0, 0, grid));
            if (ans == n) return ans - 1;
        }
        return ans - 1;

    }
};