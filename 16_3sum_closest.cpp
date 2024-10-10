#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = nums.size() - 1;
            int needed = target - nums[i];
            while (j < k) {
                if (abs(nums[i] + nums[j] + nums[k] - target) <= abs(ans - target)) ans = nums[i] + nums[j] + nums[k];
                if (nums[j] + nums[k] < needed) // then increase the sum
                    j++;
                else if (nums[j] + nums[k] > needed)
                    k--;
                else
                    return target;
            }
        }

        return ans;
    }
};

void main() {
    Solution sol;
    vector<int> nums({ 2,3,8,9,10 });
    int target = 16;
    cout << sol.threeSumClosest(nums, target);
}