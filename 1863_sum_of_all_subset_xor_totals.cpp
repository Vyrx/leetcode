#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    int rec(vector<int>& nums, int i, int cur) {
        if (i == nums.size()) return cur;
        
        return rec(nums, i + 1, cur ^ nums[i]) + rec(nums, i + 1, cur);
    }

    int subsetXORSum(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        return rec(nums, 0, 0);
    }
};