#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    void update_pq(priority_queue<pair<int, int>> &pq, const unordered_map<int, int> &umap) { // update pq based on umap
        pq = priority_queue<pair<int, int>>(); // clear the queue
        for (auto it : umap) 
            pq.push(make_pair(it.second, it.first));      
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = nums.size();
        vector<int>ans(n - k + 1, 0);
        unordered_map<int,int> umap; // value -> count
        priority_queue<pair<int, int>> pq; // pq stores pair[count, value], highest count highest value on top

        // 0 ~ k - 1 until n - k ~ n - 1
        // init
        for (int i = 0; i < k; i++) 
            umap[nums[i]]++;

        update_pq(pq, umap);
        for (int c = 0; c < x && !pq.empty(); c++) {
            ans[0] += pq.top().first * pq.top().second;
            pq.pop();
        }

        for (int i = 1; i <= n - k; i++) {
            // delete front
            if (umap[nums[i - 1]] <= 1)
                umap.erase(nums[i - 1]);
            else
                umap[nums[i - 1]]--;

            // add back
            umap[nums[i + k - 1]]++;
            update_pq(pq, umap);
            for (int c = 0; c < x && !pq.empty(); c++) {
                ans[i] += pq.top().first * pq.top().second;
                pq.pop();
            }
        }
        return ans;
    }
};

void main() {
    Solution Sol;
    vector<int> nums({ 9,2,2 });
    Sol.findXSum(nums, 3, 3);
}