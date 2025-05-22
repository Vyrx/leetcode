#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;


class Solution {
public:

    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        const int MAX_RANGE = 1e5 + 1;
        int n = nums.size(), q = queries.size();

        priority_queue<int> pq; // store r, largest r in front
        sort(queries.begin(), queries.end()); // sort from smallest l
        queries.push_back({ MAX_RANGE, MAX_RANGE });
        vector<int> ls(n + 1); // line sweep on nums
        int curOverlap = 0, qUsed = 0, qIndex = 0;

        for (int i = 0; i < n; i++) {
            curOverlap += ls[i];
            nums[i] -= curOverlap;

            // add every query thats in interval
            while (queries[qIndex][0] <= i) { // while the left end of range is <= cur index
                pq.push(queries[qIndex][1]);
                qIndex++;
            }

            // keep using current top most item in pq until its fulfilled
            while (nums[i] > 0) {
                if (pq.empty()) return -1; // no more query, cant be converted to zero array
                int curR = pq.top();
                pq.pop();
                if (curR < i) continue; // if current point already pass the range end

                // Update ls, only update end point cause start point will already pass
                ls[curR + 1]--;
                curOverlap++;
                nums[i]--;
                qUsed++;
            }
        }

        return q - qUsed;
    }
};

void main() {
    Solution S;
    vector<int> nums = { 2,0,2 };
    vector<vector<int>> queries = { {0,2}, {0,2}, {1,1} };
    cout << S.maxRemoval(nums, queries);
}