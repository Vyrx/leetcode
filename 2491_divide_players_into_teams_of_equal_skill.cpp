#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long target = 0;
        unordered_map<int, int> umap; // value -> count
        for (int i = 0; i < skill.size(); i++) {
            target += skill[i];
            umap[skill[i]]++;
        }
        target /= skill.size() / 2;

        long long chem = 0;
        for (auto &it : umap) {
            if (it.second != umap[target - it.first]) return -1;
            else if (it.first == target - it.first) {
                if (it.second % 2 != 0) return -1; // count need to be even
                chem += double(it.second) * (it.first * it.first) / 2;
            }
            else {
                chem += it.second * (it.first * (target - it.first));
                umap.erase(target - it.first);
            }
        }
        return chem;
    }
};

int main() {
    Solution Sol;
    vector<int> skill({ 5,4,4,5,5,4 });
    cout << Sol.dividePlayers(skill);
	return 0;
}