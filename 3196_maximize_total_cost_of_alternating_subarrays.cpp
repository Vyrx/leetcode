#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	typedef long long ll;
	// (sign + 1) / 2
	// -1 -> 0
	// 1 -> 1
	ll rec(vector<int>& nums, vector<vector<ll>> &dp, int i, int sign) {
		if (i >= nums.size()) return 0;
		if (dp[i][(sign + 1) / 2] != -1) return dp[i][(sign + 1) / 2];

		// choose not split vs split
		ll notSplit = nums[i] * sign + rec(nums, dp, i + 1, -sign);
		ll Split = nums[i] + rec(nums, dp, i + 1, -1);
		return dp[i][(sign + 1) / 2] = max(Split, notSplit);
	}

	long long maximumTotalCost(vector<int>& nums) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		vector<vector<ll>> dp(nums.size(), vector<ll>(2, -1)); // n x 2

		return rec(nums, dp, 0, 1);

	}
};