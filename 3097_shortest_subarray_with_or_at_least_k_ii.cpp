#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int cur_or = 0;
        int minLen = 200001;
        int left = 0;
        vector<int> oneSum(30); // sum of the number of ones in each bit
        for (int i = 0; i < nums.size(); i++) {
            cur_or |= nums[i];

            // includes cur number in oneSum
            int j = 0;
            int temp = nums[i];
            while (temp > 0) {
                oneSum[j] += temp & 1;
                temp >>= 1;
                j++;
            }

            while (cur_or >= k) {
                if (i == left) return 1;
                minLen = min(minLen, i - left + 1);

                // remove nums[left] from oneSum
                int j = 0;
                while (nums[left] > 0) {
                    oneSum[j] -= nums[left] & 1;
                    if (oneSum[j] == 0) {
                        // turn jth bit in cur_or to 0
                        cur_or = cur_or & ~(1 << j);
                    }
                    nums[left] >>= 1;
                    j++;
                }
                left++;
            }
        }

        return minLen == 200001 ? -1 : minLen;
    }
};

void main() {
    vector<int> nums = { 1, 2, 3 };
    Solution S;
    S.minimumSubarrayLength(nums, 2);
}
