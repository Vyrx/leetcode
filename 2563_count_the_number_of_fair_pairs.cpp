#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	long long countFairPairs(vector<int>& nums, int lower, int upper) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		sort(nums.begin(), nums.end());

		long long res = 0;

		int start = 1, end = nums.size() - 1;
		int left, right;
		for (int i = 0; i < nums.size() - 1; i++) {

			// find the smallest num st nums[i] + nums[start] >= lower
			int new_start = -1;
			left = i + 1, right = end;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (nums[i] + nums[mid] >= lower) {
					new_start = mid;
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			if (new_start == -1) continue;

			start = new_start;

			// find the max num st nums[i] + nums[start] <= upper
			int new_end = -1;
			left = start, right = end;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (nums[i] + nums[mid] <= upper) {
					new_end = mid;
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			if (new_end == -1) continue;

			end = new_end;

			res += end - start + 1;
		}


		return res;

	}
};

void main() {
	Solution S;
	vector<int> nums = { 6,9,4,2,7,5,10,3 };
	cout << S.countFairPairs(nums, 13, 13);
}

// 0 1 4 4 5 7

// 0 1 4 5