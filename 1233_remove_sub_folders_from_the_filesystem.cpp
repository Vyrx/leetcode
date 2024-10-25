#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<string> ans;
        sort(folder.begin(), folder.end());

        ans.push_back(folder[0]);
        for (int i = 1; i < folder.size(); i++) {
            int found = folder[i].find(ans.back());
            if (found != 0 || folder[i][ans.back().size()] != '/') // if not a subfolder of prev
                ans.push_back(folder[i]);
        }

        return ans;
    }
};

void main() {
    Solution S;
    vector<string> folder({ "/a/b/c","/a/b/ca","/a/b/d" });
    S.removeSubfolders(folder);
}