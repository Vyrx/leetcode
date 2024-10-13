#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		// Move the left side of the range per step
		// Pair -> value, index of nums
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> ans;
		vector<int> cur_range;
		vector<int> ptr(nums.size(), 0);

		// init
		int temp_min = nums[0][0], temp_max = nums[0][0];
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i][0] < temp_min) {
				temp_min = nums[i][0];
			}
			if (nums[i][0] > temp_max) temp_max = nums[i][0];

			pq.push(make_pair(nums[i][0], i));
		}
		ans = vector<int>({ temp_min, temp_max });
		cur_range = ans;

		while (true) {

			// New range is [top of pq, current max]
			pair<int, int> top = pq.top();
			if (ptr[top.second] >= nums[top.second].size() - 1) break; // if last index is reached

			ptr[top.second]++;
			int temp_val = nums[top.second][ptr[top.second]];
			if (cur_range[1] < temp_val) cur_range[1] = temp_val; // update max if new value is bigger and not from the same index as the min
			pq.push(make_pair(temp_val, top.second));

			pq.pop();
			cur_range[0] = pq.top().first; // update min

			// check if smaller
			if (cur_range[1] - cur_range[0] < ans[1] - ans[0]) ans = cur_range;
		}

		return ans;
	}
};

void main() {
	Solution Sol;
	vector<vector<int>> nums({ {4,10,15,24,26} ,{0,9,12,20},{5,18,22,30} });
	Sol.smallestRange(nums);
}