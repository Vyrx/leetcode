#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    
    UnionFind(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i; // init parent to itself
        }
        rank = vector<int>(n); // init rank to 0
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            // attach smaller rank (b) to bigger (a)
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

};

class Solution {
public:
    struct Edges {
        int u, v, weight;
        Edges(int u, int v, int weight) : u(u), v(v), weight(weight) {};
    };

    struct compEdges {
        bool operator() (Edges &lhs, Edges &rhs){
            return lhs.weight > rhs.weight; // min heap
        }
    };

    int getManhattanDist(int x1, int y1, int x2, int y2) {
        return abs(x2 - x1) + abs(y2 - y1);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // Kruskal's algorithm
        int n = points.size();
        priority_queue<Edges, vector<Edges>, compEdges> pq;

        // Store all edges in pq
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                pq.push(Edges(i, j, getManhattanDist(points[i][0], points[i][1], points[j][0], points[j][1])));
            }
        }

        UnionFind uf(n);
        int total_cost = 0;
        int num_edges = 0; // MST should have n - 1 edges

        while (num_edges < n - 1) {
            Edges cur_edge = pq.top();
            if (uf.find_set(cur_edge.u) != uf.find_set(cur_edge.v)) {
                total_cost += cur_edge.weight;
                num_edges++;
                uf.union_set(cur_edge.u, cur_edge.v);               
            }
            pq.pop();
        }
        return total_cost;
    }
};

void main() {
    Solution S;
    vector<vector<int>> points = { {0,0},{2,2},{3,10},{5,2},{7,0} };
    cout << S.minCostConnectPoints(points);
}

