#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> grid(m, vector<int>(n)); // 1 = visited, 2 = guard / wall
        int res = m * n - guards.size() - walls.size();

        for (int i = 0; i < guards.size(); i++) {
            grid[guards[i][0]][guards[i][1]] = 2;
        }
        for (int i = 0; i < walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = 2;
        }

        for (int i = 0; i < guards.size(); i++) {
            int curx = guards[i][0] - 1, cury = guards[i][1];
            while (curx >= 0) {
                if (grid[curx][cury] == 2) break;
                else if (grid[curx][cury] == 0) {
                    grid[curx][cury] = 1;
                    res--;
                }
                curx--;
            }

            curx = guards[i][0] + 1; cury = guards[i][1];
            while (curx < m) {
                if (grid[curx][cury] == 2) break;
                else if (grid[curx][cury] == 0) {
                    grid[curx][cury] = 1;
                    res--;
                }
                curx++;
            }

            curx = guards[i][0]; cury = guards[i][1] - 1;
            while (cury >= 0) {
                if (grid[curx][cury] == 2) break;
                else if (grid[curx][cury] == 0) {
                    grid[curx][cury] = 1;
                    res--;
                }
                cury--;
            }

            curx = guards[i][0]; cury = guards[i][1] + 1;
            while (cury < n) {
                if (grid[curx][cury] == 2) break;
                else if (grid[curx][cury] == 0) {
                    grid[curx][cury] = 1;
                    res--;
                }
                cury++;
            }

        }
        return res;
    }
};