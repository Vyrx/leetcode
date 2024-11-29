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
    int minimumTime(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int m = grid.size(), n = grid[0].size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, mycomp> pq; // time, i, j
        pq.push({ 0, 0, 0 });
        vector<vector<bool>> visited(m, vector<bool>(n));
        visited[0][0] = true;

        while (true) {
            int cur_t = pq.top()[0];
            int ci = pq.top()[1], cj = pq.top()[2];
            if (ci == m - 1 && cj == n - 1) return cur_t;

            if (ci != 0 && !visited[ci - 1][cj]) {
                visited[ci - 1][cj] = true;
                if (cur_t + 1 >= grid[ci - 1][cj])
                    pq.push({ cur_t + 1, ci - 1, cj });
                else if ((ci - 1 + cj) % 2 == grid[ci - 1][cj] % 2) { // check for parity, even index sum cells can only be entered at even time
                    pq.push({ grid[ci - 1][cj], ci - 1, cj });
                }
                else {
                    pq.push({ grid[ci - 1][cj] + 1, ci - 1, cj });
                }
            }
            if (ci != m - 1 && !visited[ci + 1][cj]) {
                visited[ci + 1][cj] = true;
                if (cur_t + 1 >= grid[ci + 1][cj])
                    pq.push({ cur_t + 1, ci + 1, cj });
                else if ((ci + 1 + cj) % 2 == grid[ci + 1][cj] % 2) { 
                    pq.push({ grid[ci + 1][cj], ci + 1, cj });
                }
                else {
                    pq.push({ grid[ci + 1][cj] + 1, ci + 1, cj });
                }
            }
            if (cj != 0 && !visited[ci][cj - 1]) {
                visited[ci][cj - 1] = true;
                if (cur_t + 1 >= grid[ci][cj - 1])
                    pq.push({ cur_t + 1, ci, cj - 1 });
                else if ((ci + cj - 1) % 2 == grid[ci][cj - 1] % 2) {
                    pq.push({ grid[ci][cj - 1], ci, cj - 1 });
                }
                else {
                    pq.push({ grid[ci][cj - 1] + 1, ci, cj - 1 });
                }
            }
            if (cj != n - 1 && !visited[ci][cj + 1]) {
                visited[ci][cj + 1] = true;
                if (cur_t + 1 >= grid[ci][cj + 1])
                    pq.push({ cur_t + 1, ci, cj + 1 });
                else if ((ci + cj + 1) % 2 == grid[ci][cj + 1] % 2) {
                    pq.push({ grid[ci][cj + 1], ci, cj + 1 });
                }
                else {
                    pq.push({ grid[ci][cj + 1] + 1, ci, cj + 1 });
                }
            }

            pq.pop();
        }
    }
};