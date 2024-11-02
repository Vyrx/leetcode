#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int n;
	vector<vector<int>> res;
	vector<int> cur;

	// to deal with duplicates, if a number has been skipped then it cant be added again

	void helper(int i, int prev_skip, vector<int>& candidates, int target) {
		if (target == 0) {
			res.push_back(cur);
			return;
		}
		if (target < 0 || i >= n) return;
		
		// skip cur number
		helper(i + 1, candidates[i], candidates, target);

		// add cur number 
		if (candidates[i] != prev_skip) {
			cur.push_back(candidates[i]);
			helper(i + 1, prev_skip, candidates, target - candidates[i]);
			cur.pop_back();
		}

	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		n = candidates.size();
		sort(candidates.begin(), candidates.end());

		// skip
		helper(0, 0, candidates, target);

		return res;
	}
};