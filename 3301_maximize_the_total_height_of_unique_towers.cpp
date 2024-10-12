#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        long long ans = maximumHeight[0]; int prev = maximumHeight[0];
        if (ans < maximumHeight.size()) return -1;
        for (int i = 1; i < maximumHeight.size(); i++) {
            if (maximumHeight[i] >= prev)
                prev = prev - 1;
            else prev = maximumHeight[i];
            ans += prev;
        }

        return prev <= 0 ? -1 : ans;
    }
};