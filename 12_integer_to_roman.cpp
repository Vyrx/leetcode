#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string ans = "";

        int digit = num / 1000; // AXXX
        for (int i = 0; i < digit; i++) ans += 'M';

        digit = (num / 100) % 10; // XAXX
        if (digit == 9) ans += "CM";
        else if (digit == 4) ans += "CD";
        else {
            if (digit >= 5) {
                ans += "D";
                digit -= 5;
            }
            for (int i = 0; i < digit; i++) ans += 'C';
        }

        digit = (num / 10) % 10; // XXAX
        if (digit == 9) ans += "XC";
        else if (digit == 4) ans += "XL";
        else {
            if (digit >= 5) {
                ans += "L";
                digit -= 5;
            }
            for (int i = 0; i < digit; i++) ans += 'X';
        }

        digit = num % 10; // XXXA
        if (digit == 9) ans += "IX";
        else if (digit == 4) ans += "IV";
        else {
            if (digit >= 5) {
                ans += "V";
                digit -= 5;
            }
            for (int i = 0; i < digit; i++) ans += 'I';
        }

        return ans;
    }
};