#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

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

        // Prim's algorithm
          
        int n = points.size();
        int total_cost = 0;
        vector<bool> visited(n);
        int num_visited = 0;
        priority_queue<Edges, vector<Edges>, compEdges> pq; // min weight on front

        // init
        visited[0] = true;
        num_visited++;
        for (int i = 1; i < n; i++) {
            pq.push(Edges(0, i, getManhattanDist(points[0][0], points[0][1], points[i][0], points[i][1])));
        }

        while (num_visited < n) {
            Edges cur_edge = pq.top();
            pq.pop();
            if (!visited[cur_edge.u] || !visited[cur_edge.v]) { // if one of the points is not visited
                int cur_point = visited[cur_edge.u] ? cur_edge.v : cur_edge.u; // get the not visited point
                // Add all non visited neighbors to the pq
                for (int i = 0; i < n; i++) {
                    if (!visited[i] && i != cur_point) {
                        pq.push(Edges(cur_point, i, getManhattanDist(points[cur_point][0], points[cur_point][1], points[i][0], points[i][1])));
                    }
                }
                total_cost += cur_edge.weight;
                num_visited++;
                visited[cur_point] = true;
            }
        }
        return total_cost;
    }
};

void main() {
    Solution S;
    vector<vector<int>> points = { {0,0},{2,2},{3,10},{5,2},{7,0} };
    cout << S.minCostConnectPoints(points);
}

