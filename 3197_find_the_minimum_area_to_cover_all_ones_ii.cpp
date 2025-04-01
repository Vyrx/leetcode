#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int findMin(vector<vector<int>>& grid, int up_b, int down_b, int left_b, int right_b) {
		int top, bottom, left, right;
		top = left = 1000;
		bottom = right = 0;

		for (int i = up_b; i <= down_b; i++) {
			for (int j = left_b; j <= right_b; j++) {
				if (grid[i][j]) {
					top = min(top, i);
					bottom = max(bottom, i);
					left = min(left, j);
					right = max(right, j);
				}
			}
		}
		return (bottom - top + 1) * (right - left + 1);
	}

	int splitLast2(vector<vector<int>>& grid, int up_b, int down_b, int left_b, int right_b) {
		int ans = 900;

		// split horizontal
		for (int i = up_b; i < down_b; i++) {
			ans = min(ans, findMin(grid, up_b, i, left_b, right_b) + findMin(grid, i + 1, down_b, left_b, right_b));
		}
		for (int i = left_b; i < right_b; i++) {
			ans = min(ans, findMin(grid, up_b, down_b, left_b, i) + findMin(grid, up_b, down_b, i + 1, right_b));
		}

		return ans;
	}

    int minimumSum(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

		int n = grid.size();
		int m = grid[0].size();
		int ans = 900;

		// split horizontal, take one of the two areas then split the other
		for (int i = 0; i < n - 1; i++) {
			// take top
			ans = min(ans, findMin(grid, 0, i, 0, m - 1) + splitLast2(grid, i + 1, n - 1, 0, m - 1));
			// take bottom
			ans = min(ans, splitLast2(grid, 0, i, 0, m - 1) + findMin(grid, i + 1, n - 1, 0, m - 1));
		}

		// split vertical
		for (int i = 0; i < m - 1; i++) {
			ans = min(ans, findMin(grid, 0, n - 1, 0, i) + splitLast2(grid, 0, n - 1, i + 1, m - 1));
			ans = min(ans, splitLast2(grid, 0, n - 1, 0, i) + findMin(grid, 0, n - 1, i + 1, m - 1));
		}

		return ans;

    }
};