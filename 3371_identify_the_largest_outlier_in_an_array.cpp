#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int sum = 0;
        unordered_map<int, int> umap;
        for (int& it : nums) {
            sum += it;
            umap[it]++;
        }

        sort(nums.begin(), nums.end());

        for (int i = nums.size() - 1; i >= 0; i--) {
            int t = (sum - nums[i]);
            if (t % 2 == 0 && ( umap[t / 2] >= 2 || (nums[i] != t / 2 && umap[t / 2] >= 1) )) {
                return nums[i];
            }
        }

        return -1;
    }
};

void main() {

}