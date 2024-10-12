#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	int minGroups(vector<vector<int>>& intervals) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		sort(intervals.begin(), intervals.end());

		priority_queue<int, vector<int>, greater<int>> pq;
		int ans = 0;
		for (vector<int> it : intervals) {

			while (!pq.empty() && pq.top() < it[0])
				pq.pop();
			pq.push(it[1]);
			if (pq.size() > ans) ans = pq.size();

		}
		return ans;

	}
};