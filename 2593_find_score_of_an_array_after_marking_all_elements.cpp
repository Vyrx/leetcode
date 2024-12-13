#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        vector<bool> marked(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // value, index
        for (int i = 0; i < n; i++) 
            pq.push({ nums[i], i });

        long long res = 0;
        while (!pq.empty()) {
            int in = pq.top()[1];
            if (marked[in]) {
                pq.pop();
                continue;
            }

            res += pq.top()[0];
            marked[in] = true;
            if (in > 0)
                marked[in - 1] = true;
            if (in < n - 1)
                marked[in + 1] = true;
            pq.pop();
        }
        return res;
    }
};