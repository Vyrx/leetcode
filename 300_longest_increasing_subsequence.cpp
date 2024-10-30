#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> seq; // seq[i] = index of last val of sequence of length i
        seq.push_back(0);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[seq.back()]) {
                seq.push_back(i);
                continue;
            }

            // binary search
            int left = 0; int right = seq.size() - 2;
            int in = -1;

            while (left <= right) { // look for largest number thats smaller than nums[i]
                int mid = (left + right) / 2;
                if (nums[seq[mid]] >= nums[i]) {
                    right = mid - 1;
                }
                else {
                    in = mid;
                    left = mid + 1;
                }
            }

            if (in != -1) {
                if (nums[i] < nums[seq[in + 1]]) // sequence of length in + 1 found
                    seq[in + 1] = i;
            }

            if (nums[seq[0]] > nums[i])  // check if number is smaller than cur seq of length 1
                seq[0] = i;
        }

        return seq.size();
    }
};

void main() {
    Solution S;
    vector<int>nums({ 3,5,6,2,5,4,19,5,6,7,12 });
    cout << S.lengthOfLIS(nums);
}