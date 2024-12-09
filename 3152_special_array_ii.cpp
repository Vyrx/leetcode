#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size(), q = queries.size();

        vector<int> p_sum(n);
        p_sum[0] = 1;
        for (int i = 1; i < n; i++) {
            p_sum[i] = p_sum[i - 1] + (nums[i - 1] % 2 == nums[i] % 2);
        }

        vector<bool> res(q);
        for (int i = 0; i < q; i++) {
            res[i] = p_sum[queries[i][1]] == p_sum[queries[i][0]];
        }

        return res;
    }
};