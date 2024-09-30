#include<iostream>
#include<vector>

using namespace std;

class MyCircularDeque {
public:

    struct Node {
        Node(int data) : data(data) {
            next = nullptr;
            prev = nullptr;
        }
        int data;
        Node* next;
        Node* prev;
    };

    int curSize, maxSize;
    Node* frontHead, *frontTail, *backHead, * backTail;

    MyCircularDeque(int k) {
        maxSize = k;
        curSize = 0;
        frontHead = nullptr, frontTail = nullptr, backHead = nullptr, backTail = nullptr;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        Node* newNode = new Node(value);
        curSize++;

        if (frontHead == nullptr) {
            frontHead = frontTail = newNode;
            return true;
        }

        newNode->next = frontHead;
        frontHead->prev = newNode;
        frontHead = newNode;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        Node* newNode = new Node(value);
        curSize++;

        if (backHead == nullptr) {
            backHead = backTail = newNode;
            return true;
        }

        newNode->next = backHead;
        backHead->prev = newNode;
        backHead = newNode;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        if (curSize == 1) {
            curSize--;
            delete frontHead, frontTail, backHead, backTail;
            frontHead = nullptr, frontTail = nullptr, backHead = nullptr, backTail = nullptr;
            return true;
        }

        curSize--;

        if (frontHead != nullptr) {
            Node* newHead = frontHead->next;
            if (newHead != nullptr) newHead->prev = nullptr;
            delete frontHead;
            frontHead = newHead;
            return true;
        }

        // if theres no front side
        Node* newTail = backTail->prev;
        if (newTail != nullptr) newTail->next = nullptr;
        delete backTail;
        backTail = newTail;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        if (curSize == 1) {
            curSize--;
            delete frontHead, frontTail, backHead, backTail;
            frontHead = nullptr, frontTail = nullptr, backHead = nullptr, backTail = nullptr;
            return true;
        }

        curSize--;

        if (backHead != nullptr) {
            Node* newHead = backHead->next;
            if (newHead != nullptr) newHead->prev = nullptr;
            delete backHead;
            backHead = newHead;
            return true;
        }

        // if theres no back side
        Node* newTail = frontTail->prev;
        if (newTail != nullptr) newTail->next = nullptr;
        delete frontTail;
        frontTail = newTail;
        return true;

    }

    int getFront() {
        if (isEmpty()) return -1;
        if (frontHead != nullptr) return frontHead->data;
        else return backTail->data;
    }

    int getRear() {
        if (isEmpty()) return -1;
        if (backHead != nullptr) return backHead->data;
        else return frontTail->data;
    }

    bool isEmpty() {
        return curSize <= 0;
    }

    bool isFull() {
        return curSize >= maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
    MyCircularDeque* obj = new MyCircularDeque(4);
    cout << obj->insertFront(9);
    cout << obj->deleteLast();
    cout << obj->getRear();
    cout << obj->getFront();
    cout << obj->getFront();
    cout << obj->deleteFront();
    cout << obj->insertFront(6);
    cout << obj->insertLast(5);
    cout << obj->insertFront(9);
    cout << obj->getFront();
    cout << obj->insertFront(6);

	return 0;
}