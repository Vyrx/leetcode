#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<string, int> umap;
        int ssize = s.size() / k;

        for (int i = 0; i < s.size(); i += ssize) {
            umap[s.substr(i, ssize)]++;
        }

        for (int i = 0; i < t.size(); i += ssize) {
            if (umap[t.substr(i, ssize)] <= 0) return false;
            umap[t.substr(i, ssize)]--;
        }
        return true;
    }
};

void main() {
    string s = "aabbcc";
    string t = "bbaacc";
    Solution S;
    cout << S.isPossibleToRearrange(s, t, 2);
}