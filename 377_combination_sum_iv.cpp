#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int dp[1001];

    int helper(vector<int>& nums, int target) {
        if (dp[target] != -1) return dp[target];

        int res = 0;
        for (int it : nums) {
            if (it <= target) {
                res += helper(nums, target - it);
            }
        }
        return dp[target] = res;
    }

    int combinationSum4(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        memset(dp, -1, sizeof(dp));
        dp[0] = 1;
        return helper(nums, target);
    }
};