#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    char findKthBit(int n, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int s_len = (1 << n) - 1;
        bool inverted = 0;
        int mid = (s_len + 1) / 2;

        while (k > 1) {
            if (k > mid) {
                inverted = !inverted;
                k = mid + mid - k;
            }
            else if (k == mid) return inverted ? '0' : '1';

            mid /= 2;
        }
        return inverted ? '1' : '0';
    }
};

void main() {
    Solution S;
    S.findKthBit(3, 5);
}
