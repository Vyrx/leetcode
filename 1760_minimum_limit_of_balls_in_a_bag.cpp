#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums, int op, int target) {
        for (int& it : nums) {
            op -= it / target - 1;
            if (it % target != 0) op--;
            if (op < 0) return false;
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);


        // final array size will be nums.size() + maxOperations
        int fin_size = nums.size() + maxOperations;

        // min possible ans is sum / fin_size, max possible ans is current max
        long long sum = 0;
        int left, right = 0;
        for (int& it : nums) {
            sum += it;
            right = max(it, right);
        }
        left = sum / fin_size;
        left = max(left, 1);
        int res = right;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (isPossible(nums, maxOperations, mid)) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return res;
    }
};