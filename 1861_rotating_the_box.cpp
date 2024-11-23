#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	// stone '#'
	// stationary obstacle '*'
	// Empty '.'
	vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int m = box.size(), n = box[0].size();

		for (int i = 0; i < m; i++) {
			int edge = -1; // -1 -> tbd
			for (int j = n - 1; j >= 0; j--) {
				if (box[i][j] == '.' && edge == -1) edge = j;
				else if (box[i][j] == '#' && edge != -1) {
					box[i][edge] = '#';
					box[i][j] = '.';
					edge--;
				}
				else if (box[i][j] == '*') {
					edge = -1;
				}
			}
		}

		vector<vector<char>> res(n, vector<char>(m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] = box[m - j - 1][i];
			}
		}

		return res;
	}
};