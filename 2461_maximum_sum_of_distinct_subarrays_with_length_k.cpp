#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<int, int> umap;
        long long res = 0;
        int dupe = 0;
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            umap[nums[i]]++;
            if (umap[nums[i]] == 2) dupe++;      
        }
        if (dupe == 0) res = sum;

        for (int i = 1; i < nums.size() - k + 1; i++) {
            sum -= nums[i - 1];
            umap[nums[i - 1]]--;
            if (umap[nums[i - 1]] == 1) dupe--;

            sum += nums[i + k - 1];
            umap[nums[i + k - 1]]++;
            if (umap[nums[i + k - 1]] == 2) dupe++;

            if (!dupe) res = max(res, sum);
        }
        return res;
    }
};