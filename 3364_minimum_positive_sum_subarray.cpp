#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> psum(nums.size());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            psum[i] = sum;
        }

        int res = 1000000;
        for (int i = l - 1; i < r; i++) {
            if (psum[i] > 0)
                res = min(psum[i], res);
        }

        for (int i = 1; i + l - 1 < nums.size(); i++) {
            for (int j = i + l - 1; j <= i + r - 1; j++) {
                if (j >= nums.size()) break;
                if (psum[j] - psum[i - 1] > 0)
                    res = min(psum[j] - psum[i - 1], res);
            }
        }

        return res == 1000000 ? -1 : res;
    }
};