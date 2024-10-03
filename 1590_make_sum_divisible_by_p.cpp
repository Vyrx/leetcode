#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int min_len = nums.size();

        vector<int> prefix_sum(nums.size(), -1);
        prefix_sum[0] = nums[0] % p;
        for (int i = 1; i < nums.size(); i++) {
            prefix_sum[i] = (prefix_sum[i - 1] + nums[i]) % p;
        }
        int target_sum = prefix_sum[prefix_sum.size() - 1];
        // divisible by p means target_sum should be zero, so we need to find sum of subarray equal to target_sum
        if (target_sum == 0) return 0;

        unordered_map<int, int> umap; // mod sum -> end of index with that mod sum (that has the largest size)
        int need_to_remove;
        umap[0] = -1; // if nothing is removed, size is index + 1
        for (int i = 0; i < prefix_sum.size(); i++) {
            need_to_remove = (prefix_sum[i] - target_sum + p) % p;

            // check if such sum exist
            if (umap.count(need_to_remove) > 0) {
                int cur_len = i - umap[need_to_remove];
                if (cur_len < min_len) min_len = cur_len;
            }

            // add / replace current prefix mod sum to map, guaranteed to be longest
            umap[prefix_sum[i]] = i;
        }

        /*
        // check for prefix starting from first index 0 & prefix of size 1

        for (int i = 0; i < prefix_sum.size(); i++) {
            if (nums[i] % p == target_sum) return 1;
            if (prefix_sum[i] == target_sum && i + 1 < min_length) min_length = i + 1;
        }

        // check for prefix starting from 1 and so on with size of 2 or more
        for (int i = 1; i < prefix_sum.size(); i++) {
            for (int j = i + 1; j < prefix_sum.size(); j++) {
                if (j - i + 1 > min_length) break;
                if ((prefix_sum[j] + p - prefix_sum[i - 1]) % p == target_sum) {
                    min_length = j - i + 1;
                    break;
                }
            }
        }
        */

        if (min_len == nums.size()) return -1;
        else return min_len;
    }
};

int main() {

    vector<int> arr({ 19,25,39,31,20,10,40,38,28,35,11,11,18,26,26,24,29,14,10,37 });
    int p = 23;
    Solution Sol;
    cout << Sol.minSubarray(arr, p);
    return 0;
}

// 6 3 5 2 p=9
// 6 0 5 7