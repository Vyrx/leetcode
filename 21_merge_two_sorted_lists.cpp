#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);


        ListNode *main_head, *main, *ptr1 = list1, * ptr2 = list2;
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        if (ptr1->val < ptr2->val) {
            main_head = new ListNode(ptr1->val);
            ptr1 = ptr1->next;
        }
        else {
            main_head = new ListNode(ptr2->val);
            ptr2 = ptr2->next;
        }

        main = main_head;

        while (true) {
            if (ptr1 == nullptr) {
                main->next = ptr2;
                return main_head;
            }
            if (ptr2 == nullptr) {
                main->next = ptr1;
                return main_head;
            }

            if (ptr1->val < ptr2->val) {
                main->next = new ListNode(ptr1->val);
                ptr1 = ptr1->next;
            }
            else {
                main->next = new ListNode(ptr2->val);
                ptr2 = ptr2->next;
            }
            main = main->next;

        }
        return main_head;
    }
};