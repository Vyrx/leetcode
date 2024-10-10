#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // keep monotonic decreasing sequence, lets say theres a solution [i, j] and nums[i] is larger than current 
        // minimum value k, then [k, j] is a solution more optimal than [k, j]
        // therefore the solution can only start from any of the monotonically decreasing sequence (stored in the stack)
        stack<int> decrease_in;
        decrease_in.push(0);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[decrease_in.top()]) {
                decrease_in.push(i);
            }
        }
        int maxWidth = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (nums[i] >= nums[decrease_in.top()]) { // if found keep comparing until smallest starting index possible
                maxWidth = max(maxWidth, i - decrease_in.top());
                decrease_in.pop();
                if (decrease_in.empty()) return maxWidth;
            }
        }
        return maxWidth;
    }
};