#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int cur_area = 0, temp;
        // always move the lowest height, why?
        // wlog assume height[start] < height[end], current area is height[start] * length
        // if we move height[end], the new area will be height[start] * new_length at best. 
        // Since new_length < length, the area will always be smaller and so we already have the maximum area for any rectangle that starts at index start
        // however if we move height[start], we may encounter a bigger rectangle. While length will be smaller, width will be min (height[end], height[new_start]), which could be larger than height[start]
        while (start < end) {
            temp = min(height[start], height[end]) * (end - start);
            if (cur_area < temp) cur_area = temp;
            if (height[start] < height[end])
                start++;
            else
                end--;
        }
        return cur_area;
    }
};

void main() {
    Solution Sol;
    vector<int> height({ 1,8,6,2,5,4,8,3,7 });
    cout << Sol.maxArea(height);
}