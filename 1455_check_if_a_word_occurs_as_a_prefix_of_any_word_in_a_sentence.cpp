#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if (sentence.substr(0, searchWord.size()) == searchWord) return 1;

        int sent = 1;

        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                sent++;
                if (sentence.substr(i + 1, searchWord.size()) == searchWord) return sent;
            }
        }

        return -1;
    }
};