#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canShip(int capacity, vector<int>& weights, int days) {
        int cur_sum = 0;
        int max_sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (cur_sum + weights[i] <= capacity)
                cur_sum += weights[i];
            else {
                max_sum = max(max_sum, cur_sum);
                if (weights[i] > capacity) return -1;
                cur_sum = weights[i];
                days--;
                if (days == 0) return -1;
            }
        }
        return max(max_sum, cur_sum);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int right = 0;
        for (int it : weights) {
            right += it;
        }
        int left = right / days;
        int ans = right;
        while (left <= right) {
            int middle = (left + right) / 2;
            int cs = canShip(middle, weights, days);
            if (cs != -1) {
                ans = min(middle, cs);
                right = ans - 1;
            }
            else
                left = middle + 1;
        }

        return ans;
    }
};

void main() {
    Solution S;
    vector<int> weights({ 1,2,3,4,5,6,7,8,9,10 });
    int days = 10;
    S.shipWithinDays(weights, days);
}