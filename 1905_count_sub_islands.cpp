#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	int m; int n;

	bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		if (grid2[i][j] == 0) return 1;
		grid2[i][j] = 0;

		bool res = 1;
		for (int dir = 0; dir < 4; dir++) {
			if (i + dx[dir] < 0 || i + dx[dir] >= m || j + dy[dir] < 0 || j + dy[dir] >= n) continue;

			if (!dfs(i + dx[dir], j + dy[dir], grid1, grid2)) {
				res = 0;
			}
		}

		return res && grid1[i][j];
	}
	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int res = 0;
		m = grid2.size(); n = grid2[0].size();

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid2[i][j])
					res += dfs(i, j, grid1, grid2);
			}
		}

		return res;
	}
};