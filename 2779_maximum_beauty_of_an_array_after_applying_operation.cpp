#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ls[100001];
        memset(ls, 0, sizeof(ls));

        for (int& it : nums) {
            if (it - k >= 0) {
                ls[it - k]++;
            }
            else {
                ls[0]++;
            }
            if (it + k + 1 <= 100000) {
                ls[it + k + 1]--;
            }
            else {
                ls[100000]--;
            }
        }

        int cur = 0;
        int res = 1;
        for (int& it : ls) {
            cur += it;
            res = max(cur, res);
        }
        return res;
    }
};