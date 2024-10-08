#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int unmatched = 0; // num of unmatched [
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') unmatched++;
            else {
                unmatched = max(0, unmatched - 1);
            }
        }
        return (unmatched + 1) / 2;
    }
};