#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int cnt = 1;
        string res = "";
        for (int i = 0; i < word.size() - 1; i++) {
            if (word[i] != word[i + 1]) {
                res.push_back(cnt + '0');
                res.push_back(word[i]);
                cnt = 1;
            }
            else {
                if (cnt < 9) 
                    cnt++;
                else {
                    res.push_back(cnt + '0');
                    res.push_back(word[i]);
                    cnt = 1;
                }
            }
        }
        res.push_back(cnt + '0');
        res.push_back(word.back());

        return res;
    }
};