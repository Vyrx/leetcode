#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	//items : price, beauty
	vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		vector<int> res(queries.size());
		sort(items.begin(), items.end());

		int back = 0;

		for (int i = 1; i < items.size(); i++) {
			if (items[i][1] > items[back][1]) { // when new item is found with higher max beauty
				if (items[i][0] != items[back][0]) // if price is different
					back++;
				items[back] = items[i];
			}
		}
		items.resize(back + 1);

		for (int i = 0; i < queries.size(); i++) { // find the max price thats smaller or equal than qu
			int left = 0, right = items.size() - 1;
			int fnd = 0;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (items[mid][0] <= queries[i]) {
					fnd = items[mid][1];
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			res[i] = fnd;
		}

		return res;
	}
};