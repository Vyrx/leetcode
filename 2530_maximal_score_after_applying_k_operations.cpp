#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        long long ans = 0;
        priority_queue<int> pq;
        for (auto it : nums) pq.push(it);

        while (k > 0) {
            ans += pq.top();
            pq.push(ceil(double(pq.top()) / 3));
            pq.pop();
            k--;
        }

        return ans;
        
    }
};

void main() {
    Solution Sol;
    vector<int> nums({ 756902131,995414896,95906472,149914376,387433380,848985151 });
    cout << Sol.maxKelements(nums, 6);
}