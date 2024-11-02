#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> res;
    vector<int> cur;

    void helper(int i, vector<int>& candidates, int target) {
        if (target < 0 || i >= n) return;
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        // move to next number
        helper(i + 1, candidates, target);

        // add cur number
        cur.push_back(candidates[i]);
        helper(i, candidates, target - candidates[i]);
        cur.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        n = candidates.size();
        sort(candidates.begin(), candidates.end());

        helper(0, candidates, target);

        return res;
    }
};