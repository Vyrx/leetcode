#include<iostream>
#include<vector>
#include<string>
#include<bitset>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // divide into segments based on number of set bits
        // all elements in current segment should be larger than all in prev segment (just need to check largest in prev)

        int prev_large = 0, cur_large = nums[0];
        int set_bits = bitset<9>(nums[0]).count();

        for (int i = 1; i < nums.size(); i++) {
            if (bitset<9>(nums[i]).count() == set_bits) {
                cur_large = max(nums[i], cur_large);
            }
            else {
                prev_large = cur_large;
                cur_large = nums[i];
                set_bits = bitset<9>(nums[i]).count();
            }
            if (nums[i] < prev_large) return false;
        }
        return true;
    }
};