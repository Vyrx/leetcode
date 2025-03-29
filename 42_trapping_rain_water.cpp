#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // height of water in each tile is min(max height to the left, max height to the right)
        // then the amount of water is that minus the elevation on the current tile
        int n = height.size();
        int ans = 0;

        vector<int> max_h(n, 0); // maximum height to the left of height[i]
        int cur_h = 0;
        for (int i = 0; i < n; i++) {
            max_h[i] = cur_h;
            cur_h = max(cur_h, height[i]);
        }

        cur_h = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans += max(min(max_h[i], cur_h) - height[i], 0);
            cur_h = max(cur_h, height[i]);
        }

        return ans;

    }
};