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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *ptr1 = dummy, * ptr2 = head->next;

        while (ptr2 != nullptr) {

            ptr1->next->next = ptr2->next;
            ptr2->next = ptr1->next;
            ptr1->next = ptr2;
            
            ptr1 = ptr1->next->next;
            if (ptr2->next->next == nullptr) break;
            ptr2 = ptr2->next->next->next;
        }

        return dummy->next;

    }
};

void main() {
    Solution Sol;
    ListNode* head = new ListNode(1);
    ListNode* cur = new ListNode(2);
    head->next = cur;
    cur->next = new ListNode(3);
    cur = cur->next;
    cur->next = new ListNode(4);
    Sol.swapPairs(head);
}