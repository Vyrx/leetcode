#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(nums.begin(), nums.end());
        int halfN = nums.size() / 2;
        double res = 50;
        for (int i = 0; i < halfN; i++) {
            res = min(res, double(nums[i] + nums[nums.size() - 1 - i]) / 2);
        }
        return res;
    }
};