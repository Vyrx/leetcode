#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if (k == 1) return nums;

        int cur_len = 1;
        vector<int> res;
        for (int i = 1; i < k - 1; i++) {
            if (nums[i] == nums[i - 1] + 1)
                cur_len++;
            else
                cur_len = 1;
        }

        for (int i = k - 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                cur_len++;
                if (cur_len >= k) {
                    cur_len = k - 1;
                    res.push_back(nums[i]);
                }
                else 
                    res.push_back(-1);
            }
            else {
                cur_len = 1;
                res.push_back(-1);
            }
        }

        return res;
    }
};