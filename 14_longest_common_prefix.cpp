#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int min_len = INT_MAX;
        for (string it : strs) 
            min_len = min(min_len, int(it.size()));
        string ans = "";
        for (int i = 0; i < min_len; i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j - 1][i] != strs[j][i]) return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};