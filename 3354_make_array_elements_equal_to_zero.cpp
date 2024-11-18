#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int sum = 0;
        for (int &n : nums) {
            sum += n;
        }

        if (sum == 0) return nums.size() * 2;
        
        int res = 0;
        int cur_sum = 0;
        int comb = sum % 2 ? 1 : 2;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            if (nums[i] == 0 && (cur_sum == sum / 2 || cur_sum == (sum + 1) / 2)) {
                while (nums[i] == 0) {
                    res += comb;
                    i++;
                    if (i == nums.size()) return res;
                }
                cur_sum += nums[i];
            }
            if (cur_sum > (sum + 1) / 2) break;
        }
        return res;
    }
};