#include<iostream>
#include<string>
using namespace  std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // When two string are the same
        if (sentence1 == sentence2) return true;

        // Assume sentence1 < sentence2
        if (sentence1.size() > sentence2.size()) return areSentencesSimilar(sentence2, sentence1);

        int s1_start = -1, s1_end = sentence1.size();
        
        for (int i = 0; i <= sentence1.size(); i++) { // check from front
            if (i == sentence1.size()) {
                if (sentence2[i] == ' ')
                    return true; // s1 is prefix of s2
                break;
            }
            if (sentence1[i] != sentence2[i]) break;
            else if (sentence1[i] == ' ' && sentence2[i] == ' ') s1_start = i;
        }

        for (int i = 1; i <= sentence1.size() + 1; i++) { // check from behind
            if (i == sentence1.size() + 1) {
                if (sentence2[sentence2.size() - i] == ' ')
                    return true; // s1 is suffix of s2
                break;
            }
            if (sentence1[sentence1.size() - i] != sentence2[sentence2.size() - i]) break;
            else if (sentence1[sentence1.size() - i] == ' ' && sentence2[sentence2.size() - i] == ' ') 
                s1_end = sentence1.size() - i;
        }
        if (s1_start >= s1_end) return true;
        else return false;
    }
};

void main() {
    Solution Sol;
    string s1 = "A B B";
    string s2 = "A B C D B B";
    cout << Sol.areSentencesSimilar(s1, s2);
}