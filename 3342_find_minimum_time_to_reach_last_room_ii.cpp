#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<tuple>
using namespace std;

class Solution {
public:
    typedef tuple<int, int, int, int> Tup; // cur time, val, i, j
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int m = moveTime.size(), n = moveTime[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n));
        priority_queue<Tup, vector<Tup>, greater<Tup>> toVisit;

        visited[0][0] = true;
        toVisit.push(make_tuple(0, 0, 0, 0));

        while (true) {
            Tup cur = toVisit.top();
            int x = get<2>(cur), y = get<3>(cur);
            toVisit.pop();

            if (x == m - 1 && y == n - 1)
                return get<0>(cur);

            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i], new_y = y + dy[i];
                if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || visited[new_x][new_y]) continue;
                toVisit.push(make_tuple(max(get<0>(cur), moveTime[new_x][new_y]) + ((new_x + new_y) % 2 == 0 ? 2 : 1), moveTime[new_x][new_y], new_x, new_y));
                visited[new_x][new_y] = true;
            }
        }
    }
};