#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:

    int longestSquareStreak(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(nums.begin(), nums.end());
        
        int cnt = 1;
        unordered_map<long long, int> umap; // num, seq length

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < 46341 && umap.count(nums[i] * nums[i])) {
                umap[nums[i]] = umap[nums[i] * nums[i]] + 1;
                cnt = max(cnt, umap[nums[i]]);
            }
            else
                umap[nums[i]] = 1;
            
        }

        return cnt == 1 ? -1 : cnt;
    }
};

void main() {
    Solution S;
    vector<int> nums({ 2, 3, 5, 6, 7 });
    S.longestSquareStreak(nums);
}