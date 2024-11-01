#include<iostream>
#include<string>
using namespace std;

class Solution {
public:

	string countAndSay(int n) {
		if (n == 1) return "1";

		string s = countAndSay(n - 1);
		int count = 1;

		string res = "";

		for (int i = 1; i < s.size(); i++) {
			if (s[i] == s[i - 1]) count++;
			else {
				res.push_back(count + '0');
				res.push_back(s[i - 1]);
				count = 1;
			}
		}

		res.push_back(count + '0');
		res.push_back(s.back());


		return res;
	}
};

void main() {
	Solution S;
	cout << S.countAndSay(5);
}