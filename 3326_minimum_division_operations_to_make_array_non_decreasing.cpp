#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> umap;

    int minOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;

        for (int i = nums.size() - 2; i >= 0; i--) {
            while (nums[i] > nums[i + 1]) {
                int largest_f = find_largest_factor(nums[i]);
                if (largest_f == -1) return -1;
                nums[i] /= largest_f;
                ans++;
            }
        }

        return ans;
    }

    int find_largest_factor(int num) {
        if (num % 2 == 0) return num / 2;

        if (umap.count(num)) return umap[num];

        for (int i = 3; i <= sqrt(num); i += 2) {
            if (num % i == 0) {   
                return umap[num] = num / i;
            }
        }

        return -1;
    }
};

void main() {
    Solution S;
    vector<int> nums({240, 2, 11});
    S.minOperations(nums);
}