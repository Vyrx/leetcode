#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long sumScores(string &s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = s.size();
        vector<int> z(n); // z function
        long long res = n;
        int l = 0, r = 0; // [l,r) being the last segment found that match the prefix
        s = s + '$'; // to ensure that we can't explore to the right past array size

        for (int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = min(z[i - l], r - i);
            }

            // check if we can extend current segment
            while (s[i + z[i]] == s[z[i]])
                z[i]++;

            // if new rightmost segment found, update l r
            if (i + z[i] >= r) {
                l = i;
                r = i + z[i];
            }
            res += z[i];
        }
        return res;
    }
};