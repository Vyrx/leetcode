#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool parse_and(string &s, int &ptr) {
        bool out = true;
        while (true) {
            if (!parse(s, ptr) && out) out = false;

            if (s[ptr] == ')') break;
            else ptr += 1;
        }
        ptr += 1;
        return out;
    }

    bool parse_or(string &s, int &ptr) {
        bool out = false;
        while (true) {
            if (parse(s, ptr) && !out) out = true;

            if (s[ptr] == ')') break;
            else ptr += 1;
        }
        ptr += 1;
        return out;
    }
    bool parse(string &s, int &ptr) {
        if (s[ptr] == 'f') {
            ptr += 1;
            return false;
        }
        else if (s[ptr] == 't') {
            ptr += 1;
            return true;
        }
        else if (s[ptr] == '&') {
            ptr += 2;
            return parse_and(s, ptr);
        }
        else if (s[ptr] == '|') {
            ptr += 2;
            return parse_or(s, ptr);
        }
        else if (s[ptr] == '!') {
            ptr += 2;
            bool out = !parse(s, ptr);
            ptr += 1;
            return out;
        }
        return false;
    }

    bool parseBoolExpr(string &expression) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ptr = 0;
        return parse(expression, ptr);
    }
};