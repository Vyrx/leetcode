#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> partitionLabels(string s) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n = s.size();
		unordered_map<char, int> start, finish; //for each char, store the first appearance and last appearance

		for (int i = 0; i < n; i++) {
			if (start.find(s[i]) == start.end()) { // if char is not in umap
				start[s[i]] = i;
			}
			finish[s[i]] = i;
		}

		vector<int> ls(n, 0);

		for (auto& it : start) {
			ls[it.second]++;
			ls[finish[it.first]]--;
		}

		int counter = 0, size = 0;
		vector<int> ans;

		for (int i = 0; i < n; i++) {
			size++;
			counter += ls[i];
			if (counter == 0) {
				ans.push_back(size);
				size = 0;
			}
		}

		return ans;
	}
};