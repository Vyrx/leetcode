#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> diff(nums.size() + 1);

        for (int i = 0; i < queries.size(); i++) {
            diff[queries[i][0]]++;
            diff[queries[i][1] + 1]--;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += diff[i];
            if (sum < nums[i]) return false;
        }
        return true;
        
    }
};