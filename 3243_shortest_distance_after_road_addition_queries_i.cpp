#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> res;
        vector<vector<int>> next(n - 1);
        
        for (vector<int> &quer : queries) {
            next[quer[0]].push_back(quer[1]);

            queue<pair<int, int>> q; // node
            vector<bool> visited(n);
            q.push(make_pair(0, 0));

            while (true) {
                int node = q.front().first;

                if (node == n - 1) {
                    res.push_back(q.front().second);
                    break;
                }

                if (!visited[node + 1]) {
                    q.push(make_pair(node + 1, q.front().second + 1));
                    visited[node + 1] = true;
                }
                for (int& it : next[node]) {
                    if (!visited[it]) {
                        q.push(make_pair(it, q.front().second + 1));
                        visited[it] = true;
                    }
                }
                q.pop();
            }

        }

        return res;
    }
};

void main() {
    Solution S;
    vector<vector<int>> queries;
    S.shortestDistanceAfterQueries(5, queries);
}