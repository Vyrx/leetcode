#include<iostream>
#include<vector>
using namespace std;

class CustomStack {
public:
    int maxSize;
    vector<int> stack;
    int start, end;

    CustomStack(int maxSize): maxSize(maxSize) {
        stack = vector<int>(maxSize, -1);
        start = end = -1;
    }

    bool isEmpty() {
        return (start == -1 || end == -1);
    }

    void push(int x) {
        // If full, don't push
        if ((start == 0 && end == maxSize - 1) || end == start - 1) 
            return;

        // Init if stack is empty
        if (isEmpty()) {
            start = end = 0;
            stack[0] = x;
            return;
        }

        // Push normally
        if (end == maxSize - 1) end = 0;
        else end++;

        stack[end] = x;
    }

    int pop() {
        // If empty, don't pop
        if (isEmpty()) return -1;

        // Pop normally
        int val = stack[end];


        if (start == end) start = end = -1; // If the last element is popped mark as empty
        else if (end == 0) end = maxSize - 1;
        else end--;

        return val;

    }

    void increment(int k, int val) {

        if (isEmpty()) return;

        int i = start;
        while (true) {          
            if (k <= 0) return;
            stack[i] += val;
            if (i == end) return;
            i++;
            if (i >= maxSize) i = 0;
            k--;
        }
    }
};

// 1 <= maxSize, x, k <= 1000
// 0 <= val <= 100

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main() {
    CustomStack stk = CustomStack(3); // Stack is Empty []
    stk.push(1);                          // stack becomes [1]
    stk.push(2);                          // stack becomes [1, 2]
    stk.pop();                            // return 2 --> Return top of the stack 2, stack becomes [1]
    stk.push(2);                          // stack becomes [1, 2]
    stk.push(3);                          // stack becomes [1, 2, 3]
    stk.push(4);                          // stack still [1, 2, 3], Do not add another elements as size is 4
    stk.increment(5, 100);                // stack becomes [101, 102, 103]
    stk.increment(2, 100);                // stack becomes [201, 202, 103]
    stk.pop();                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
    stk.pop();                            // return 202 --> Return top of the stack 202, stack becomes [201]
    stk.pop();                            // return 201 --> Return top of the stack 201, stack becomes []
    stk.pop();                            // return -1 --> Stack is empty return -1.
    return 0;
}