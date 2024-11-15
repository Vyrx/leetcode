#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = arr.size();
        int front = -1, back = -1; // from index 0 to front array is increasing
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                front = i - 1;
                break;
            }
        }
        if (front == -1) return 0;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                back = i + 1;
                break;
            }
        }
        //if (arr[0] > arr[back]) return back; // result is just the sufix

        // for index back until n - 1 check how much need to be removed
        int res = n; // res is num of removed entries from prefix and suffix 
        int cur_front = 0; // the largest num thats <= arr[back]
        int cur_back = back;

        // set cur_back to be the first number thats bigger than arr[0];
        while (arr[cur_back] < arr[0]) {
            cur_back++;
            if (cur_back == n) break;
        }

        while (cur_back < n) {
            while (arr[cur_front] <= arr[cur_back]) {
                if (cur_front == front) {
                    res = min(res, front - cur_front + cur_back - back);
                    return min(back - front - 1 + res, min(n - 1 - front, back));
                }
                cur_front++;  
            }
            cur_front--;
            res = min(res, front - cur_front + cur_back - back);
            cur_back++;
        }
        // consider cases where only prefix / only suffix is included
        return min(back - front - 1 + res, min(n - 1 - front, back));
    }
};

void main() {
    Solution S;
    vector<int> arr = { 8,9,5,8,11,14,2 };
    cout << S.findLengthOfShortestSubarray(arr);
}