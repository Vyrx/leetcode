#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        // Binary search approach -> O (n^2 * log(n))

        /*for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                int needed = -(nums[i] + nums[j]);
                if (binary_search(nums.begin() + j + 1, nums.end(), needed))
                    ans.push_back(vector<int>{nums[i], nums[j], needed});
            }
        }*/

        // Hash map approach -> n + n^2 = O (n^2)

        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]] = i; // store index of each value
        }
            

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                int needed = -(nums[i] + nums[j]);
                if (umap.count(needed) > 0 && umap[needed] > j)
                    ans.push_back(vector<int>{nums[i], nums[j], needed});
            }
        }

        return ans;
    }
};

void main() {
    Solution Sol;
    vector<int> nums({ -1,0,1,2,-1,-4 });
    Sol.threeSum(nums);
}