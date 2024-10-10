#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < int(nums.size()) - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < int(nums.size()) - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int m = j + 1, n = nums.size() - 1;
                long long needed = (long long)(target) - (long long)(nums[i] + nums[j]);
                while (m < n) {

                    if (nums[m] + nums[n] < needed)
                        m++;
                    else if (nums[m] + nums[n] > needed)
                        n--;
                    else {
                        ans.push_back(vector<int>({ nums[i], nums[j], nums[m], nums[n] }));
                        m++;
                        n--;
                        while (m < n && nums[m] == nums[m - 1]) m++;
                        while (m < n && nums[n] == nums[n + 1]) n--;
                    }
                }
            }
        }

        return ans;
    }
};

void main() {
    Solution Sol;
    vector<int> nums({ 0 });
    int target = 0;
    Sol.fourSum(nums, target);
}