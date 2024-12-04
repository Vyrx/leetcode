#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int m = str1.size(), n = str2.size();
        int i = -1, j = 0;

        while (j < n) {
            if (++i >= m) return false;
            int t = str2[j] - str1[i];
            if (t == 0 || t == 1 || t == -25)
                j++;
        }
        return true;
    }
};