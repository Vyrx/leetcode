#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<array>
using namespace std;

class Solution {
public:
	bool sumExists(vector<int>& nums, bool (&dp)[201][20001], int sum, int i) {
		if (i < 0 || sum < 0) return false;
		if (!dp[i][sum]) return dp[i][sum];
		if (sum == 0) return true;


		if (sumExists(nums, dp, sum - nums[i], i - 1) || sumExists(nums, dp, sum, i - 1)) {
			return true;
		}
		else {
			for (int j = 0; j <= i; j++) {
				dp[j][sum] = false;
			}
			return false;
		}
	}

	bool canPartition(vector<int>& nums) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int sum = 0;
		for (int& it : nums) {
			sum += it;
		}
		if (sum % 2 != 0) return false;
		sum /= 2;

		// possible sum: 1 ~ 20000
		bool dp[201][20001]; 
		// dp[i][j]: 1 if theres a subset nums[0] ~ nums[i] that sums to j
		// 0 if there isnt
		memset(dp, true, sizeof(dp));

		return sumExists(nums, dp, sum, nums.size() - 1);
	}
};

void main() {
	Solution S;
	vector<int> nums = { 1,5, 5,11};
	cout << S.canPartition(nums);
}