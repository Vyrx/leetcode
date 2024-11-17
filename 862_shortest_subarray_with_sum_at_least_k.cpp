#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<deque>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if (nums[0] >= k) return 1;

        // subarray sum = difference between two prefix sums
        // keep track of prefix sums, ordered from smallest

        deque<pair<long long, int>> dq; // {prefix sum, index}
        long long sum = nums[0];
        dq.push_back({ sum, 0 });
        int res = 100001;

        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            if (sum >= k) res = min(res, i + 1);

            while (sum - dq.front().first >= k) {
                res = min(res, i - dq.front().second);
                dq.pop_front(); // any sum afterwards minus this prefix sum will always be longer
                if (dq.empty()) return res;
            }

            // remove sums larger than current sum because subtracting with current sum will guarantee a more efficient solution (larger sum amount with shorter subarray length)
            while (!dq.empty() && dq.back().first >= sum) {
                dq.pop_back();
            }

            dq.push_back({ sum, i });
        }

        return res == 100001 ? -1 : res;
    }
};