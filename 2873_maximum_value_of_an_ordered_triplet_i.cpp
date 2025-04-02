#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> prefix(nums.size()), suffix(nums.size());
        prefix[1] = nums[0];
        for (int i = 2; i < nums.size() - 1; i++) {
            prefix[i] = max(prefix[i - 1], nums[i - 1]);
        }
        suffix[nums.size() - 2] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 1; i--) {
            suffix[i] = max(suffix[i + 1], nums[i + 1]);
        }

        long long ans = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            ans = max(ans, (long long)(prefix[i] - nums[i]) * suffix[i]);
        }
        return ans;
    }
};

void main() {
    Solution S;
    vector<int> nums = { 10,13,6,2 };
    cout << S.maximumTripletValue(nums);
}