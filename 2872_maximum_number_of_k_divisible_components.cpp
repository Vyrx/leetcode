#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int res;

    int dfs(int node, vector<vector<int>>& edges, vector<int>& values, int k, vector<bool> &visited) {
        visited[node] = true;

        int sum = 0;
        for (auto& it : edges[node]) {
            if (!visited[it]) {
                values[node] += dfs(it, edges, values, k, visited);
            }
        }

        if (values[node] % k == 0) {
            res++;
            return 0; 
        }

        return values[node] % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> n_edges(n);
        for (auto& it : edges) {
            n_edges[it[0]].push_back(it[1]);
            n_edges[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n);

        res = 0;
        dfs(0, n_edges, values, k, visited);
        return res;

    }
};

void main() {
    Solution S;
    int n = 5;
    vector<vector<int>> edges = { {0,2}, {1,2}, {1,3}, {2,4} };
    vector<int> values = { 1,8,1,4,4 };
    int k = 6;
    cout << S.maxKDivisibleComponents(n, edges, values, k);
}