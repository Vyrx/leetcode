#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> decrypt(vector<int>& code, int k) {
		vector<int> res(code.size());

		if (k > 0) {
			int sum = 0;
			for (int i = 1; i <= k; i++) {
				sum += code[i];
			}
			res[0] = sum;

			for (int i = 1; i < code.size(); i++) {
				sum -= code[i];
				sum += code[(i + k) % code.size()];
				res[i] = sum;
			}
		}
		else if (k < 0) {
			int sum = 0;
			for (int i = code.size() - 1; i >= code.size() + k; i--) {
				sum += code[i];
			}
			res[0] = sum;
			for (int i = 1; i < code.size(); i++) {
				sum += code[i - 1];
				sum -= code[(i + k + code.size() - 1) % code.size()];
				res[i] = sum;
			}
		}
		return res;
	}
};
