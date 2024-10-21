#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
	void backtrack(int i, int count, int &maxCount, string &s, unordered_set<string> &seen) {
		if (count + s.size() - i <= maxCount) return; // if splitting the rest of string into individual char still provides a count smaller than max count
		if (i == s.size()) {
			maxCount = max(maxCount, count);
		}

		for (int end = i; end < s.size(); end++) {
			string cur = s.substr(i, end - i + 1);
			if (seen.find(cur) == seen.end()) { // if cur is not in seen
				seen.insert(cur);
				backtrack(end + 1, count + 1, maxCount, s, seen);
				seen.erase(cur);
			}
		}
	}

	int maxUniqueSplit(string& s) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		unordered_set<string> seen;
		int maxCount = 0;
		backtrack(0, 0, maxCount, s, seen);
		return maxCount;
	}
};

void main() {
	Solution S;
	string s = "aa";
	S.maxUniqueSplit(s);
}
