#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> count(k, 0); // index i -> counter of mod k
        for (auto it : arr) {
            int temp = it % k;
            if (temp < 0) temp += k;
            count[temp]++;
        }
        for (int i = 1; i <= count.size() / 2; i++) { // ignore when mod value is 0, guaranteed to be even
            if (i == k - i && count[i] % 2 != 0) return false;
            if (count[i] != count[k - i]) return false;
        }
        return true;
    }
};

// arr.length == n
// 1 <= n <= 105
// n is even.
// - 109 <= arr[i] <= 109
// 1 <= k <= 105

int main() {
    Solution Sol;
    vector<int> arr = vector<int>({ -10,10 });
    int k = 2;
    cout << Sol.canArrange(arr, k);
    return 0;
}
