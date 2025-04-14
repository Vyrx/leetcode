#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    const int NORM = 10000; // normalize possible sums
    
    int rec(const vector<int>& nums, int (&dp)[20][20001], int i, int sum) {
        if (i == -1) return 0;
        if (dp[i][sum + NORM] != -1) return dp[i][sum + NORM];

        return dp[i][sum + NORM] = rec(nums, dp, i - 1, sum - nums[i]) + rec(nums, dp, i - 1, sum + nums[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int dp[20][20001]; // dp[i][j] = number of ways to form (j - 1000) using index 0 to i
        memset(dp, -1, sizeof(dp));
        if (nums[0] == 0) dp[0][NORM] = 2;
        else {
            dp[0][-nums[0] + NORM] = 1;
            dp[0][nums[0] + NORM] = 1;
        }

        return rec(nums, dp, nums.size() - 1, target);
    }
};