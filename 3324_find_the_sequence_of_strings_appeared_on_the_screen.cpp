#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> stringSequence(string target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<string> ans;
        string cur_s = "";


        for (char c : target) {
            cur_s.push_back('a');
            ans.push_back(cur_s);
            while (c != cur_s.back()) {
                cur_s.back() += 1;
                ans.push_back(cur_s);
            }
        }
        return ans;
    }
};