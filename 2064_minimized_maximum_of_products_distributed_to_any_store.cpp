#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isDitributeable(int val, int n, vector<int>& quantities) {
        for (int i = 0; i < quantities.size(); i++) {
            n -= quantities[i] / val;
            if (quantities[i] % val) n--;
            if (n < 0) return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        // binary search over all possible values
        long long sum = 0;
        int min_val, max_val;
        for (int i = 0; i < quantities.size(); i++) {
            sum += quantities[i];
        }
        min_val = ceil((double)sum / n); // average score per store
        max_val = *max_element(quantities.begin(), quantities.end());

        int res;
        while (min_val <= max_val) {
            int mid = (min_val + max_val) / 2;
            // check if possible to distribute such that each store has mid or less products

            if (isDitributeable(mid, n, quantities)) {
                res = mid;
                max_val = mid - 1;
            }
            else {
                min_val = mid + 1;
            }
        }
        return res;
    }
};

void main() {
    Solution S;
    vector<int> quantities = { 11, 6 };
    cout << S.minimizedMaximum(6, quantities);
}