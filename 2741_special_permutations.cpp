#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    const int N = 1e9 + 7;
    int allOne;
    int dp[1 << 14][14];

    int recur(int combination, int index_last, vector<int>& nums, vector<vector<int>>& adj) {
        if (dp[combination][index_last] != -1) return dp[combination][index_last];
        if (combination == allOne) return 1;

        long long ans = 0;
        for (auto i : adj[index_last]) {
            if (!(1 << i & combination))
                ans += recur(1 << i | combination, i, nums, adj);
        }
        return dp[combination][index_last] = ans % N;
    }

    int specialPerm(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();

        // number of combination possible until the end with current sequence
        // vector<vector<int>> dp(1 << n, vector<int>(n, -1)); // dp [combination of index used][index of last number used]

        memset(dp, -1, sizeof(dp));

        sort(nums.begin(), nums.end());

        vector<vector<int>> adj(n); // for each index i, store all indexes that can be adjacent
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        long long ans = 0;
        allOne = (1 << n) - 1;

        for (int i = 0; i < n; i++)
            ans += recur(1 << i, i, nums, adj);


        return ans % N;
    }
};

void main() {
    Solution S;
    vector<int> nums({ 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8191 });
    S.specialPerm(nums);
}