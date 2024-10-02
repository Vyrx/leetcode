#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[(high + low) / 2];
        // move pivot to last (high)
        swap(arr[(high + low) / 2], arr[high]);

        int pivot_index = low;

        for (int i = low; i < high; i++) {
            if (arr[i] < pivot) {
                swap(arr[pivot_index], arr[i]);
                pivot_index++;
            }
        }

        // swap pivot to pivot_index
        swap(arr[pivot_index], arr[high]);
        return pivot_index;
    }
    
    void quickSort(vector<int>& arr, int low, int high) {

        if (low >= high) return;

        int pivot_index = partition(arr, low, high); // pivotted element is now sorted

        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        unordered_map<int, int> umap;

        // sort
        quickSort(sorted_arr, 0, sorted_arr.size() - 1);
        sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());
        for (int i = 0; i < sorted_arr.size(); i++) umap[sorted_arr[i]] = i + 1;

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = umap[arr[i]];
        }

        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr({ 37,12,28,9,100,56,80,5,12 });
    sol.arrayRankTransform(arr);
    return 0;
}