#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minimumArea(vector<vector<int>>& grid) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int top, bottom, left, right;
		top = left = 1000;
		bottom = right = 0;

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
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
};