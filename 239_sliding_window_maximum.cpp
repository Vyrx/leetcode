#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> ans;
        // array in dq should always be decreasing, dq.front() will always contain the current max
        deque<int> dq; 
        dq.push_back(nums[0]);

        for (int i = 1; i < k; i++) {
            // if current number is greater than a preceding number then the current number will always yield more optimal result than the preceding number in future sliding window, so we remove it since it will never be the maximum
            while (!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            // > instead of >= to solve duplicate issue with dq.front() == nums[i - k]
            // if a number that is pushed is equal to current maximum it wont pop the current maximum, the current maximum will only be popped if the sliding window passed it
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());

        for (int i = k; i < nums.size(); i++) {
            if (dq.front() == nums[i - k]) dq.pop_front();

            while (!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);

            ans.push_back(dq.front());
        }
        return ans;
    }
};
