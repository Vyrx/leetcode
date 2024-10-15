#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long long swaps = 0;
        int end;
        for (end = s.size() - 1; end >= 0; end--) {
            if (s[end] != '1') break;
        }

        for (int i = end - 1; i >= 0; i--) {
            if (s[i] == '1') {
                swaps += end - i;
                end--;
            }
        }
        return swaps;
    }
};