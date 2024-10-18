#include<iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            else return -dividend;
        }
        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) return 1;
            else return 0;
        }
        bool sign = 0;
        int ans = 0;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) sign = 1;
        if (dividend > 0) dividend = -dividend;
        if (divisor < 0) divisor = -divisor;

        // dividend -> negative, divisor -> positive
        while (dividend <= -divisor) {
            dividend += divisor;
            ans++;
        }
        if (sign) return ans;
        else return -ans;
    }
};

void main() {
    Solution S;
    S.divide(2147483647, 1);
}