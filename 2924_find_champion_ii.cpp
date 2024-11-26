#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<bool> pointed(n);
        
        for (const vector<int>& it : edges) {
            pointed[it[1]] = true;
        }

        int res = -1;

        for (int i = 0; i < n; i++) {
            if (!pointed[i]) {
                if (res != -1) return -1;
                res = i;
            }
        }
        
        return res;
    }
};