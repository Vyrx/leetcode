#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<array>
using namespace std;

class Solution {
public:
    struct mycomp {
        bool operator() (const array<int, 3>& x, const array<int, 3>& y) {
            return x[0] > y[0];
        }
    };
    int minimumObstacles(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int m = grid.size(), n = grid[0].size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, mycomp> pq; // obstacle passed, i, j
        vector<vector<bool>> visited(m, vector<bool>(n));
        pq.push({ 0,0,0 });
        visited[0][0] = true;

        while (true) {
            int ci = pq.top()[1], cj = pq.top()[2];
            if (ci == m - 1 && cj == n - 1) return pq.top()[0];

            if (ci != 0 && !visited[ci - 1][cj]) {
                visited[ci - 1][cj] = true;
                pq.push({ pq.top()[0] + grid[ci - 1][cj], ci - 1, cj });
            }
            if (ci != m - 1 && !visited[ci + 1][cj]) {
                visited[ci + 1][cj] = true;
                pq.push({ pq.top()[0] + grid[ci + 1][cj], ci + 1, cj });
            }
            if (cj != 0 && !visited[ci][cj - 1]) {
                visited[ci][cj - 1] = true;
                pq.push({ pq.top()[0] + grid[ci][cj - 1], ci, cj - 1});
            }
            if (cj != n - 1 && !visited[ci][cj + 1]) {
                visited[ci][cj + 1] = true;
                pq.push({ pq.top()[0] + grid[ci][cj + 1], ci, cj + 1});
            }

            pq.pop();
        }
    }
};

void main() {
    Solution S;
    vector<vector<int>> grid = { {0,1,1}, {1,1,0}, {1,1,0} };
    cout << S.minimumObstacles(grid);
}