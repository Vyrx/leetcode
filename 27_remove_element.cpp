#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int i = 0;  int j = 0;
        for (; i < nums.size(); i++) {
            if (nums[i] == val) {
                continue;
            }
            nums[j] = nums[i];
            j++;
        }
        return j;
    }
};