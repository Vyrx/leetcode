#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	// 1 4 8 13
	// 4 4 8 13
	// 8 8 8 13
	int maxFrequency(vector<int>& nums, int k) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		sort(nums.begin(), nums.end());

		int ans = 1;
		int left = 0, right = 1; // two pointers, consider subarray nums[left] ~ nums[right]
		long long k_used = 0;
		
		while (right < nums.size()) {
			// After moving to the right, all items from nums[left] ~ nums[right - 1] all have values nums[right - 1]
			// We need to match those items to nums[right]
			k_used += (long long)(nums[right] - nums[right - 1]) * (right - left);

			// Now all item in the subarray have value nums[right]

			while (k_used > k) {
				// Refund k
				k_used -= nums[right] - nums[left];
				left++;
			}
			ans = max(ans, right - left + 1);
			right++;
		}
		return ans;
	}
};