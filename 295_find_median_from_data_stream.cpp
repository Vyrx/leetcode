#include<iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> lower; // lower = max heap,
    priority_queue<int, vector<int>, greater<int>> upper; //upper = min heap
    bool isOdd;

    MedianFinder() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        isOdd = false;
        lower.push(INT_MIN);
    }

    void addNum(int num) {
        // keep size of heap to either k and k (when even) or k + 1 and k (when odd)
        if (num < lower.top()) {
            lower.push(num);
            if (isOdd) { // current size is k + 2 and k
                upper.push(lower.top());
                lower.pop();
            }
        }
        else {
            upper.push(num);
            if (!isOdd) {
                lower.push(upper.top());
                upper.pop();
            }
        }
        isOdd = !isOdd;
    }

    double findMedian() {
        if (isOdd) return lower.top();
        else return double(lower.top() + upper.top()) / 2;
    }
};

void main() {
    MedianFinder M;
    M.addNum(-1);
    M.addNum(-2);
    M.addNum(-3);
}
