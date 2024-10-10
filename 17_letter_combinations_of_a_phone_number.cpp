#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, string> keyboard =
    {
        {'2' , "abc" },
        {'3' , "def" },
        {'4' , "ghi" },
        {'5' , "jkl" },
        {'6' , "mno" },
        {'7' , "pqrs"},
        {'8' , "tuv" },
        {'9' , "wxyz"}
    };

    void recur(string &digits, vector<string> &combinations, int pos, string cur) {
        if (pos >= digits.size()) {
            combinations.push_back(cur);
            return;
        }

        for (char c : keyboard[digits[pos]]) {
            recur(digits, combinations, pos + 1, cur + c);
        }
    }

    vector<string> letterCombinations(string &digits) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if (!digits.size()) return vector<string>();
        
        vector<string> combinations;
        recur(digits, combinations, 0, "");

        return combinations;
    }
};

void main() {
}