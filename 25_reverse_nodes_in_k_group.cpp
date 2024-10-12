#include<iostream>
#include<vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// d -> 1 -> 2 -> 3
// 0    1    2    3
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        vector<ListNode*> vec(k + 1, head);
        ListNode* temp = dummy;
        for (int i = 0; i < k + 1; i++) {
            vec[i] = temp;
            temp = temp->next;
        }

        ListNode* newStart;
        while (true) {
            newStart = vec[k]->next;
            for (int i = k; i >= 2; i--) {
                vec[i]->next = vec[i - 1];
            }
            vec[1]->next = newStart;
            vec[0]->next = vec[k];

            // move all vec elements
            temp = vec[1];
            for (int i = 0; i < k + 1; i++) {
                if (temp == nullptr) return dummy->next;
                vec[i] = temp;
                temp = temp->next;
            }
        }
        return dummy->next;
    }
};