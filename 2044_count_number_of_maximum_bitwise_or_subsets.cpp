#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, int &ans, int max_or, int index, int cur_val) {
        if (index >= nums.size()) {
            if (cur_val == max_or) ans++;
        }
        else {
            backtrack(nums, ans, max_or, index + 1, cur_val | nums[index]); // accept nums[index]
            backtrack(nums, ans, max_or, index + 1, cur_val); // don't accept
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int max_or = 0;
        for (int i = 0; i < nums.size(); i++) 
            max_or |= nums[i];
        
        int ans = 0;
        // for every item in nums, choose whether to include or not to include (2^nums.size() possibilities)
        backtrack(nums, ans, max_or, 0, 0);
        return ans;
    }
};