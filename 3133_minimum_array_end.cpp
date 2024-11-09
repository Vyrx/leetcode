#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // take x as base template, replace the 0s in x with n - 1 in binary
        // ex: x = 4 ([0][0]1[0]), n - 1 = 2 (10) -->  ([0][1]1[0])

        bitset<27> num(x);
        int n_min_one = n - 1;
        int i = 0;
        while (n_min_one > 0) {
            if (!num[i]) {
                num[i] = n_min_one & 1;
                n_min_one >>= 1;
            }
            i += 1;
        }
        return num.to_ullong();

    }
};