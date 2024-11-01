#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {

        if (s.size() < 3) return s;

        int ptr = 2;

        for (int i = 2; i < s.size(); i++) {
            if (s[i] != s[ptr - 1] || s[i] != s[ptr - 2]) {
                s[ptr] = s[i];
                ptr++;
            }
        }
        s.resize(ptr);

        return s;
    }
};