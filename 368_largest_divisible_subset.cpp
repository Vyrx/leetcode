#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(nums.begin(), nums.end());

        // dp[i]: size of subset ending at nums[i]
        vector<int> dp(nums.size(), 1);

        // keep track of index of prev item in the seq before current item
        vector<int> prev(nums.size(), -1);

        int max_length = 1;
        int last_ind = 0;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    if (dp[i] > max_length) {
                        max_length = dp[i];
                        last_ind = i;
                    }
                }
            }
        }

        vector<int> ans(max_length);
        for (int i = max_length - 1; i >= 0; i--) {
            ans[i] = nums[last_ind];
            last_ind = prev[last_ind];
        }

        return ans;
    }
};