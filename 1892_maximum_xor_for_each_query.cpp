#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
using namespace std;

class Solution {
public:
	vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int num = (1 << maximumBit) - 1;

		vector<int> res(nums.size());

		for (int i = 0; i < nums.size(); i++) {
			num ^= nums[i];
			res[nums.size() - 1 - i] = num;
		}

		return res;

	}
};