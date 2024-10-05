#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) { // keep char count of s1, iterate thru s2
        unordered_map<char, int> s1_count, s2_count;
        for (char c : s1) 
            s1_count[c]++;
        int start = 0, end = 0;
        while (start < s2.size() && end < s2.size()) {

            if (s1_count.count(s2[end]) > 0) { // if the char is in s1
                s2_count[s2[end]]++;

                if (end - start + 1 == s1.size()) {

                    for (auto i = s2_count.begin();;i++) {
                        if (i == s2_count.end()) return true;
                        if (i->second != s1_count[i->first]) break;
                    }

                    s2_count[s2[start]]--; // reduce the count of the first element by one
                    if (s2_count[s2[start]] == 0) s2_count.erase(s2[start]);
                    start++;
                }
                end++;
            }
            else { // if the char is not in s1
                s2_count.clear();
                start = ++end;
            }
        }
        return false;
    }
};

void main() {
    Solution Sol;
    string s1 = "adc";
    string s2 = "dcda";
    cout << Sol.checkInclusion(s1, s2);
  
}