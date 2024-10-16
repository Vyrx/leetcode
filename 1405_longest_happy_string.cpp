#include<iostream>
#include<string>
using namespace std;

class Solution {
public:

    string longestDiverseString(int a, int b, int c) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        string ans = "";
        char last = ' ';
        int count = 0;

        while (true) {
            if (a >= b && a >= c && a > 0) {
                if (last == 'a' && count >= 2) {
                    if (b >= c && b != 0) {
                        ans += 'b';
                        if (last == 'b') count++;
                        else count = 1;
                        last = 'b';
                        b--;
                    }
                    else if (c >= b && c != 0) {
                        ans += 'c';
                        if (last == 'c') count++;
                        else count = 1;
                        last = 'c';
                        c--;
                    }
                    else break;
                }
                else {
                    ans += 'a';
                    if (last == 'a') count++;
                    else count = 1;
                    last = 'a';
                    a--;
                }
            }
            else if (b >= a && b >= c && b > 0) {
                if (last == 'b' && count >= 2) {
                    if (a >= c && a != 0) {
                        ans += 'a';
                        if (last == 'a') count++;
                        else count = 1;
                        last = 'a';
                        a--;
                    }
                    else if (c >= a && c != 0) {
                        ans += 'c';
                        if (last == 'c') count++;
                        else count = 1;
                        last = 'c';
                        c--;
                    }
                    else break;
                }
                else {
                    ans += 'b';
                    if (last == 'b') count++;
                    else count = 1;
                    last = 'b';
                    b--;
                }
            }
            else if (c >= a && c >= b && c > 0) {
                if (last == 'c' && count >= 2) {
                    if (a >= b && a != 0) {
                        ans += 'a';
                        if (last == 'a') count++;
                        else count = 1;
                        last = 'a';
                        a--;
                    }
                    else if (b >= a && b != 0) {
                        ans += 'b';
                        if (last == 'b') count++;
                        else count = 1;
                        last = 'b';
                        b--;
                    }
                    else break;
                }
                else {
                    ans += 'c';
                    if (last == 'c') count++;
                    else count = 1;
                    last = 'c';
                    c--;
                }
            }
            else break;
        }

        return ans;

    }
};