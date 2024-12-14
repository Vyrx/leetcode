#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        map<int, int> m; // val : count
        m[nums[0]]++;
        long long res = 1;

        int begin = 0;
        for (int end = 1; end < n; end++) {
            m[nums[end]]++;
            while (m.rbegin()->first - m.begin()->first > 2) {
                m[nums[begin]]--;
                if (m[nums[begin]] == 0) {
                    m.erase(nums[begin]);
                }
                begin++;
            }
            res += end - begin + 1;
        }
        return res;
    }
};

void main() {
    Solution S;
    vector<int> nums = { 1,2,3 };
    S.continuousSubarrays(nums);
}