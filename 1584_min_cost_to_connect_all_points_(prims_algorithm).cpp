#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    struct Edges {
        int u, weight; // only store the vertex thats not visited
        Edges(int u, int weight) : u(u), weight(weight) {};
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
            pq.push(Edges(i, getManhattanDist(points[0][0], points[0][1], points[i][0], points[i][1])));
        }

        while (num_visited < n) {
            Edges cur_edge = pq.top();
            pq.pop();
            if (!visited[cur_edge.u]) { // if the point isnt visited yet
                visited[cur_edge.u] = true;

                // Add all non visited neighbors to the pq
                for (int i = 0; i < n; i++) {
                    if (!visited[i]) {
                        pq.push(Edges(i, getManhattanDist(points[cur_edge.u][0], points[cur_edge.u][1], points[i][0], points[i][1])));
                    }
                }
                total_cost += cur_edge.weight;
                num_visited++;
                
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

