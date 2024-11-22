#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<string, int> umap; // combination: count
        //if (matrix[0].size() == 1) return matrix.size();

        for (auto& m : matrix) {
            bool prev = m[0];
            string comb = "";
            int cnt = 1;
            

            for (int i = 1; i < m.size(); i++) {
                if (m[i] == prev) {
                    cnt++;
                }
                else {
                    comb += "_";
                    comb += to_string(cnt);
                    prev = !prev;
                    cnt = 1;
                }
            }

            comb += "_";
            comb += to_string(cnt);
            umap[comb]++;
        }
        int res = 1;
        for (auto& it : umap) {
            res = max(res, it.second);
        }

        return res;
    }
};

void main() {
    Solution S;
    vector<vector<int>> matrix = { {1,0,0,0,0,0,0,0,0,0,0,0}, {1,1,1,1,1,1,1,1,1,1,1,0} };
    cout << S.maxEqualRowsAfterFlips(matrix);
}