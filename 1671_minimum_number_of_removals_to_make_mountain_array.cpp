#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> inc_seq; // inc_seq[i] = index of last val of increasing sequence of length i
        inc_seq.push_back(0);
        vector<int> inc_len(nums.size(), 1); // inc_len[i] = length of longest increasing seq ending at nums[i]

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[inc_seq.back()]) {
                inc_seq.push_back(i);
                inc_len[i] = inc_seq.size();
                continue;
            }

            // binary search
            int left = 0; int right = inc_seq.size() - 2;
            int in = -1;

            while (left <= right) { // look for largest number thats smaller than nums[i]
                int mid = (left + right) / 2;
                if (nums[inc_seq[mid]] >= nums[i]) {
                    right = mid - 1;
                }
                else {
                    in = mid;
                    left = mid + 1;
                }
            }

            if (in != -1) {
                if (nums[i] < nums[inc_seq[in + 1]]) { // sequence of length in + 1 found
                    inc_seq[in + 1] = i;
                    inc_len[i] = in + 2;
                }
            }

            if (nums[inc_seq[0]] > nums[i])  // check if number is smaller than cur inc_seq of length 1
                inc_seq[0] = i;
        }

        int ans = 1; // max length of mountain array

        vector<int> dec_seq;
        dec_seq.push_back(nums.size() - 1);

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > nums[dec_seq.back()]) {
                dec_seq.push_back(i);
                if (inc_len[i] != 1) // needs to be increasing with length at least 2
                    ans = max(ans, (int)dec_seq.size() + inc_len[i] - 1);
                continue;
            }

            // binary search
            int left = 0; int right = dec_seq.size() - 2;
            int in = -1;

            while (left <= right) { // look for largest number thats smaller than nums[i]
                int mid = (left + right) / 2;
                if (nums[dec_seq[mid]] >= nums[i]) {
                    right = mid - 1;
                }
                else {
                    in = mid;
                    left = mid + 1;
                }
            }

            if (in != -1 && nums[i] <= nums[dec_seq[in + 1]]) {  // sequence of length in + 1 found
                    dec_seq[in + 1] = i;
                    ans = max(ans, in + 1 + inc_len[i]);
            }

            if (nums[dec_seq[0]] > nums[i]) 
                dec_seq[0] = i;
        }

        return nums.size() - ans;
    }
};

void main() {
    Solution S;
    vector<int>nums({ 9,8,1,7,6,5,4,3,2,1 });
    cout << S.minimumMountainRemovals(nums);
}