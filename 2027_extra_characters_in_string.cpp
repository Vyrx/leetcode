#include<iostream>
#include<vector>

using namespace std;

vector<int> DP(50,0);

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        return findMin(s, s.length(), dictionary);
    }

    int findMin(string s, int index, vector<string>& dictionary) {
        if (index < 0) return INT_MAX;
        int extraChar;
        return min(extraChar, findMin(s, index - 1, dictionary));
    }
};

int main() {
    Solution S;
    string s;
    vector<string> dictionary;
    s = "leetscode";
    dictionary = {"leet", "code", "leetcode"};
    cout << S.minExtraChar(s, dictionary) << endl;
	return 0;
}