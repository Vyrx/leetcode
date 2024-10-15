#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int start = 0; int count = 0; int ans = 0; int prefixEven = 0;
        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] % 2 == 1) count++;

            while (start < end && (count > k || nums[start] % 2 == 0)) {
                if (nums[start] % 2 == 1) {
                    prefixEven = 0;
                    count--;
                }
                else
                    prefixEven++;

                start++;
            }

            if (count == k)
                ans += 1 + prefixEven;
        }
        return ans;
    }
};