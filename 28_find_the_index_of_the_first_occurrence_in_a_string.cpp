#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int i = 0;
        for (;; i++) {
            if (i + needle.size() > haystack.size()) return -1;
            if (haystack.substr(i, needle.size()) == needle) return i;
        }
    }
};