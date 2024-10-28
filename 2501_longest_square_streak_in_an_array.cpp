#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:

	const int MAX_SQ = 46341;
	int dp[100001]; // each possible value of nums[i]

	int longestSquareStreak(vector<int>& nums) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		memset(dp, 0, sizeof(dp));
		int mx = 1;
		for (auto it: nums) {
			dp[it] = 1;
			mx = max(mx, it);
		}

		int cnt = 1;

		for (int i = 2; i <= mx; i++) {
			if (dp[i] && int(sqrt(i)) * int(sqrt(i)) == i) { // if i exists and is a perfect square
				dp[i] += dp[int(sqrt(i))];
				cnt = max(dp[i], cnt);
			}
		}
		return cnt == 1 ? -1 : cnt;
	}
};

void main() {
	Solution S;
	vector<int> nums({ 4, 16, 2 });
	cout << S.longestSquareStreak(nums);
}