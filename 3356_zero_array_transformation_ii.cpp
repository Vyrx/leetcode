#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isAllZeroes(vector<int>& arr, vector<int>& lines) {
        int cur_lines = 0;
        for (int i = 0; i < arr.size(); i++) {
            cur_lines += lines[i];
            if (arr[i] - cur_lines > 0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& arr, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> lines(arr.size() + 1);
        int cur_lines = 0;
        int prev_k = 0;
        int left = 0; int right = queries.size();
        int res = -1;

        // binary search on size of queries
        while (left <= right) {
            int mid = (left + right) / 2; // The number of queries used

            // Spent too much time thinking if this is O(m) or O(log m)

            if (mid > prev_k) { // add queries
                for (int i = prev_k; i < mid; i++) {
                    lines[queries[i][0]] += queries[i][2];
                    lines[queries[i][1] + 1] -= queries[i][2];
                }
            }
            else { // remove queries
                for (int i = mid; i < prev_k; i++) {
                    lines[queries[i][0]] -= queries[i][2];
                    lines[queries[i][1] + 1] += queries[i][2];
                }
            }
            prev_k = mid;

            if (isAllZeroes(arr, lines)) { // k is valid
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return res;
    }
};

int main() {
    Solution S;
    vector<int> arr{ 5 };
    vector<vector<int>> queries{ {0,0,5}, {0,0,1}, {0,0,3}, {0,0,2} };
    cout << S.minZeroArray(arr, queries);
    return 0;
}