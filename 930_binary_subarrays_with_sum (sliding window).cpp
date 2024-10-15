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

        int ans = 0;
        int start = 0;
        int curSum = 0;
        int prefixZero = 0;
        for (int end = 0; end < nums.size(); end++) {
            curSum += nums[end];

            while (start < end && (curSum > goal || nums[start] == 0)) {
                if (nums[start] == 1)
                    prefixZero = 0;
                else
                    prefixZero++;

                curSum -= nums[start];
                start++;
            }

            if (curSum == goal) {
                ans += 1 + prefixZero;
            }
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