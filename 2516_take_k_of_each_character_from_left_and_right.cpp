#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<algorithm>
using namespace std;

class Solution {
public:
	int takeCharacters(string s, int k) {
		if (k == 0) return 0;
		int res = 0; //elements removed

		int cnt[3] = {};
		
		for (auto& c : s)
			cnt[c - 'a']++;
		if (cnt[0] < k || cnt[1] < k || cnt[2] < k) return -1;

		// find the longest subsequence removal that still make the string valid
		int left = 0, right = 0;
		while (right < s.size()) {
			int in = s[right] - 'a';
			cnt[in]--;

			while (cnt[in] < k) {
				cnt[s[left] - 'a']++;
				left++;
			}

			res = max(res, right - left + 1);
			right++;
		}

		return s.size() - res;
	}
};

void main() {
	Solution S;
	string s = "aabaaaacaabc";
	cout << S.takeCharacters(s, 2);
}