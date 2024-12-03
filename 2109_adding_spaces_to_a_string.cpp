#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        string res(s.size() + spaces.size(), ' ');
        spaces.push_back(0);
        int i = 0, j = 0;
        while (i < s.size()) {
            if (i == spaces[j]) {
                res [i + j] = ' ';
                j++;
            }
            res[i + j] = s[i];
            i++;
        }
        return res;
    }
};