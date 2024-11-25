#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <unordered_set>
#include <queue>
#include<utility>
using namespace std;

class Solution {
public:
	int slidingPuzzle(vector<vector<int>>& board) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		string solved = "123450";
		unordered_set<string> visited;
		queue <pair<vector<vector<int>>, int> > q; // cur state, moves

		q.push(make_pair(board, 0));

		while (!q.empty()) {
			vector<vector<int>> cur = q.front().first;

			string s = "";
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 3; j++) {
					s += to_string(cur[i][j]);
				}
			}

			if (s == solved) return q.front().second;
			if (visited.find(s) != visited.end()) {
				q.pop();
				continue;
			}

			visited.insert(s);

			int zi, zj;

			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 3; j++) {
					if (cur[i][j] == 0) {
						zi = i;
						zj = j;
						break;
					}
				}
			}

			// move 0 to all 4 cardinal directions
			if (zi != 0) {
				swap(cur[zi][zj], cur[zi - 1][zj]);
				q.push(make_pair(cur, q.front().second + 1));
				swap(cur[zi][zj], cur[zi - 1][zj]);
			}
			if (zi != 1) {
				swap(cur[zi][zj], cur[zi + 1][zj]);
				q.push(make_pair(cur, q.front().second + 1));
				swap(cur[zi][zj], cur[zi + 1][zj]);
			}
			if (zj != 0) {
				swap(cur[zi][zj], cur[zi][zj - 1]);
				q.push(make_pair(cur, q.front().second + 1));
				swap(cur[zi][zj], cur[zi][zj - 1]);
			}
			if (zj != 2) {
				swap(cur[zi][zj], cur[zi][zj + 1]);
				q.push(make_pair(cur, q.front().second + 1));
			}
			q.pop();
		}
		return -1;
	}
};

void main() {
	Solution S;

	vector<vector<int>> board = { {1,2,3},{4,0,5} };
	S.slidingPuzzle(board);
}