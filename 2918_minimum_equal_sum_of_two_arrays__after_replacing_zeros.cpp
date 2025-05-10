#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        long long min1, min2;
        min1 = min2 = 0;
        bool hasZero1, hasZero2;
        hasZero1 = hasZero2 = false;

        for (auto& item : nums1) {
            min1 += item;
            if (item == 0) {
                min1 += 1;
                hasZero1 = true;
            }
        }
        for (auto& item : nums2) {
            min2 += item;
            if (item == 0) {
                min2 += 1;
                hasZero2 = true;
            }
        }

        // assume min1 > min2
        if (min1 < min2) {
            swap(min1, min2);
            swap(hasZero1, hasZero2);
        }

        if (min2 != min1 && !hasZero2) return -1;
        return min1;
    }
};