#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	long long countGood(vector<int>& nums, int k) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		long long res = 0;
		int l = 0, r = 0;
		int num_pairs = 0;
		int n = nums.size();

		unordered_map<int, int> count;
		count[nums[0]]++;

		while (true) {

			r++;
			if (r >= n) return res;
			count[nums[r]]++;
			num_pairs += count[nums[r]] - 1; // if the count goes from n - 1 to n then there are n - 1 new pairs


			while (num_pairs >= k) {
				res += (long long)n - r;
				count[nums[l]]--;
				num_pairs -= count[nums[l]];
				l++;
			}
		}

		return res;
	}
};

void main() {
	Solution S;
	vector<int> nums = { 3,1,4,3,2,2,4 };
	int k = 2;
	S.countGood(nums, k);
}