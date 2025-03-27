#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int minimumIndex(vector<int>& nums) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		unordered_map<int, int> umap;
		for (int& it : nums)
			umap[it]++;

		int dom = nums[0];
		for (auto& it : umap) {
			if (it.second > umap[dom])
				dom = it.first;
		}

		vector<int> cnt(nums.size(), 0);
		int dom_count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == dom) dom_count++;
			cnt[i] = dom_count;
		}

		for (int i = 0; i < cnt.size() - 1; i++) {
			//try split at each index
			if (cnt[i] > (float)(i + 1) / 2 && dom_count - cnt[i] > (float)(nums.size() - i - 1) / 2)
				return i;
		}
		return -1;
	}
};