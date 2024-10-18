#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string &s, vector<string>& words) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> ans;
        int word_length = words[0].size();
        int substr_length = word_length * words.size();
        if (substr_length > s.size()) return ans;
        
        unordered_map<string, int> word_count;
        for (string it : words) word_count[it] += 1;

        unordered_map<string, int> cur_count;
        int tracked = 0;
        int num_sub = s.size() / word_length - words.size();

        for (int j = 0; j < word_length; j++) {
            for (int i = j; i < substr_length; i += word_length) {
                string temp = s.substr(i, word_length);
                if (word_count.count(temp) > 0) {
                    cur_count[temp]++;
                    if (cur_count[temp] <= word_count[temp]) tracked++;
                }
            }
            if (tracked == words.size()) ans.push_back(j);

            for (int i = 1; i <= num_sub; i++) {
                // remove first word
                string temp = s.substr((i - 1) * word_length + j, word_length);
                if (cur_count[temp] > 0) {
                    cur_count[temp]--;
                    if (cur_count[temp] < word_count[temp]) tracked--;
                }

                // add last word
                temp = s.substr(word_length * (i + words.size() - 1) + j, word_length);
                if (word_count.count(temp) > 0) {
                    cur_count[temp]++;
                    if (cur_count[temp] <= word_count[temp]) tracked++;
                }

                if (tracked == words.size()) ans.push_back(i * word_length + j);
            }
            tracked = 0;
            cur_count.clear();
        }

        return ans;
    }
};

void main() {
    Solution S;
    string s = "barfoothefoobarman";
    vector<string> words = { "foo","bar" };
    S.findSubstring(s, words);
}