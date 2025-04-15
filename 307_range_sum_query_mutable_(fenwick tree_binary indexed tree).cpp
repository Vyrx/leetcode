#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class NumArray {
public:
    vector<int> bit; // 1-indexed binary indexed tree
    vector<int> nums;

    NumArray(vector<int>& nums) {
        bit = vector<int>(nums.size() + 1); // init all to be 0
        this->nums = nums;
        for (int i = 0; i < nums.size(); i++) {
            update_bit(i + 1, nums[i]);
        }
    }

    void update_bit(int i, int val) {
        // increase the value of bit[i] and its parents by val
        int max_in = bit.size() - 1;
        while (i <= max_in) {
            bit[i] += val;
            i += (i & -i);
        }
    }

    int query_bit(int i) {
        // obtain sum from index 1 to i
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }

    void update(int index, int val) {
        // nums[index] correspond to bit[index + 1]
        update_bit(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return query_bit(right + 1) - query_bit(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */