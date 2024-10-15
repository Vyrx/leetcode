#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> prefix_sum(nums.size(), 0);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        unordered_map<int, int> umap; // sum -> count
        umap[0] = 1; // for combinations starting from beginning
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (umap.count(prefix_sum[i] - goal) > 0) {
                ans += umap[prefix_sum[i] - goal];
            }
            umap[prefix_sum[i]]++;
        }
        return ans;
    }
};

void main() {
    vector<int> nums = { 0,1,1,1,1 };
    int goal = 3;
    Solution S;
    cout << S.numSubarraysWithSum(nums, goal);
}