#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = weights.size();
        if (k == 1) return 0;
        vector<int> adjSum(n - 1);
        for (int i = 0; i < n - 1; i++) {
            adjSum[i] = weights[i] + weights[i + 1];
        }

        sort(adjSum.begin(), adjSum.end());
        long long ans = 0;
        for (int i = 0; i < k - 1; i++) {
            ans += adjSum[n - 2 - i];
            ans -= adjSum[i];
        }

        return ans;
    }
};