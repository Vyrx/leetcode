#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> top_cnt(7), btm_cnt(7), both_cnt(7);
        int n = tops.size();

        for (int i = 0; i < n; i++) {
            if (tops[i] == bottoms[i]) {
                both_cnt[tops[i]]++;
            }
            else {
                top_cnt[tops[i]]++;
                btm_cnt[bottoms[i]]++;
            }
        }

        for (int i = 1; i <= 6; i++) {
            if (top_cnt[i] + btm_cnt[i] + both_cnt[i] == n) {
                return min(top_cnt[i], btm_cnt[i]);
            }
        }

        return -1;
    }
};