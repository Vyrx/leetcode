#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int sum = 0;
        for (int i = 0; i < num.size(); i += 2)
            sum += num[i] - '0';
        for (int i = 1; i < num.size(); i += 2)
            sum -= num[i] - '0';
        return !sum;
    }
};