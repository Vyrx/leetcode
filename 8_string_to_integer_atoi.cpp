#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long int val = 0;
        bool isPositive = true;
        int i = 0;

        // Whitespace
        for (; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            else break;
        }

        // Signedness
        for (; i < s.size(); i++) {
            if (s[i] == '-') {
                isPositive = false;
                i++;
                break;
            }
            else if (s[i] == '+') {
                i++;
                break;
            }
            else break;
        }

        // Conversion
        for (; i < s.size(); i++) {
            if (s[i] < '0' || s[i] > '9') break;

            val = val * 10 + int(s[i]) - 48;

            // Rounding
            if (isPositive && val > INT_MAX) return INT_MAX;
            else if (!isPositive && -val < INT_MIN) return INT_MIN;

        }

        if (isPositive) return val;
        else return -val; 
    }
};

void main() {
    string s = "42";
    Solution Sol;
    cout << Sol.myAtoi(s);
}