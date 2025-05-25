#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int longestPalindrome(vector<string>& words) {
		unordered_map<string, int> uset;
		int res = 0;
		int double_cnt = 0;

		for (auto& item : words) {

			string rev = item;
			swap(rev[0], rev[1]);
			if (uset[rev] > 0) {
				res += 4;
				uset[rev]--;
				if (item == rev) double_cnt--;
			}
			else {
				uset[item]++;
				if (item == rev) double_cnt++;
			}

		}
		if (double_cnt) res += 2;
		return res;
	}
};