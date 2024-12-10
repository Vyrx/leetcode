#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<string, int> umap;
        int cur_len = 1;
        int ssize = s.size();

        umap[{s[0]}] = 1;
        for (int i = 1; i < ssize; i++) {
            if (s[i] == s[i - 1]) cur_len++;
            else cur_len = 1;

            for (int j = 1; j <= cur_len; j++) {
                umap[string(j, s[i])]++;
            }
        }

        int res = -1;
        for (auto& it : umap) {
            if (it.second >= 3)
                res = max(int(it.first.size()), res);
        }

        return res;
    }
};