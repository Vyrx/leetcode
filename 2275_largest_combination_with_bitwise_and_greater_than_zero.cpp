#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        //int bit_cnt[24];
        vector<int> bit_cnt(24);

        for (auto it : candidates) {
            bitset<24> binary(it);
            for (int i = 0; i < 24; i++) 
                bit_cnt[i] += binary[i];
        }

        return *max_element(bit_cnt.begin(), bit_cnt.end());
    }
};