#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        long long res = 0;
        priority_queue<int> pq;
        for (int& it : gifts) {
            res += it;
            pq.push(it);
        }

        while (k--) {
            res = res - pq.top() + sqrt(pq.top());
            pq.push(sqrt(pq.top()));
            pq.pop();
        }

        return res;
    }
};