#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> res;
        unordered_map<int, int> out_in; // node, out edge - in edge
        unordered_map<int, queue<int>> adj;

        for (vector<int>& it : pairs) {
            adj[it[0]].push(it[1]);
            out_in[it[0]]++;
            out_in[it[1]]--;
        }

        // starting node is either with out edge one more than in edge or any node if all node has equal in and out
        int start = pairs[0][0];
        for (auto& it : out_in) {
            if (it.second == 1) {
                start = it.first;
                break;
            }
        }
        
        // int edge_cnt = pairs.size();
        // int cnt = 0;
        vector<int> seq;
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int cur = s.top();
            if (!adj[cur].empty()) {
                s.push(adj[cur].front());
                adj[cur].pop();
            }
            else {
                seq.push_back(cur);
                s.pop();
            }
        }

        for (int i = seq.size() - 1; i >= 1; i--) {
            res.push_back({ seq[i], seq[i - 1] });
        }

        return res;
    }
};

void main() {
    Solution S;
    vector<vector<int>> pairs = { {1,3}, {3,2}, {2,1} };
    S.validArrangement(pairs);
}