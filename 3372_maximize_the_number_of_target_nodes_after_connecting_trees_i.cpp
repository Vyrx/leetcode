#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int dfs(int node, int prev, int dist, const int max_dist, vector<vector<int>> &edges) {

        if (dist == max_dist) return 1;

        int res = 0;
        for (int &it : edges[node]) {
            if (it != prev) {
                res += dfs(it, node, dist + 1, max_dist, edges);
            }
        }
        return res + 1;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> n_edges1(n);
        vector<vector<int>> n_edges2(m);

        for (vector<int>& it : edges1) {
            n_edges1[it[0]].push_back(it[1]);
            n_edges1[it[1]].push_back(it[0]);
        }
        for (vector<int>& it : edges2) {
            n_edges2[it[0]].push_back(it[1]);
            n_edges2[it[1]].push_back(it[0]);
        }

        int dist2 = 0; // max number of nodes with dist k - 1 on 2nd tree
        if (k > 0) {
            for (int i = 0; i < m; i++) {
                dist2 = max(dfs(i, -1, 0, k - 1, n_edges2), dist2);
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = dist2 + dfs(i, -1, 0, k, n_edges1);
        }
        return res;
    }
};