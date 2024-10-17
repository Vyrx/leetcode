#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<queue<int>> q (10, queue<int>()); // for digit 0 ~ 9

        int count = log10(num);
        for (int i = count; i >= 0; i--) 
            q[int(num / pow(10, i)) % 10].push(count - i);

        int cur_in = 0, cur_digit = 9;
        while (cur_digit > 0) { // never swap with 0
            while (!q[cur_digit].empty()) {

                if (q[cur_digit].front() != cur_in) {

                    // find the last index of current digit
                    while (q[cur_digit].size() > 1) q[cur_digit].pop();

                    // replace digit in cur_in with digit in q[cur_digit]
                    int frontDigit = int(num / pow(10, count - cur_in)) % 10;
                    num = num - (frontDigit * pow(10, count - cur_in)) + (cur_digit * pow(10, count - cur_in));
                    num = num - (cur_digit * pow(10, count - q[cur_digit].front())) + (frontDigit * pow(10, count - q[cur_digit].front()));
                    return num;
                }
                q[cur_digit].pop();
                cur_in++;
            }
            cur_digit--;
        }
        return num;
    }
};

void main() {
    Solution S;
    cout << S.maximumSwap(98368);
}