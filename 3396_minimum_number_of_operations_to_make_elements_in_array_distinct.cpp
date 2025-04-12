#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_set<int> uset;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (uset.find(nums[i]) != uset.end()) return (i / 3) + 1;
            uset.insert(nums[i]);
        }
        return 0;
    }
};