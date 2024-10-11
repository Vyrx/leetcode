#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* pt = head;
        int count = 0;
        while (pt != nullptr) {
            pt = pt->next;
            count++;
        }
        // if the element removed is the first element
        if (count == n) return head->next;

        pt = head;
        for (int i = 1;; i++) {
            if (i == count - n) {
                pt->next = pt->next->next;
                return head;
            }
            pt = pt->next;
        }
    }
};