#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string &s, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int left = 0; int right = 0;
        int ans = 0;

        unordered_map<char, int> umap;
        while (right < s.size()) {
            umap[s[right]]++;
            while (umap[s[right]] == k) {
                ans += s.size() - right;
                umap[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};

void main() {
    Solution S;
    string s = "abacb";
    int k = 2;
    S.numberOfSubstrings(s, k);
}