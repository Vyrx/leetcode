#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> ans = { -1, -1 };

        int left = 0;
        int right = nums.size() - 1;
        int found = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else {
                found = mid;
                break;
            }
        }

        if (found == -1) return ans;

        int temp_right = found;
        while (left <= temp_right) {
            int mid = (left + temp_right) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) temp_right = mid - 1;
            else {
                if (mid == 0 || nums[mid - 1] < target) {
                    ans[0] = mid;
                    break;
                }
                else temp_right = mid - 1;
            }
        }

        while (found <= right) {
            int mid = (found + right) / 2;
            if (nums[mid] < target) found = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else {
                if (mid == nums.size() - 1 || nums[mid + 1] > target) {
                    ans[1] = mid;
                    break;
                }
                else found = mid + 1;
            }
        }

        return ans;
    }
};