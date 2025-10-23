#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

int main() {
    // create circular list with one node
    Node* head = new Node(10);
    head->next = head;
    head->prev = head;
    Node* tail = head;

    // insert at beginning
    Node* newNode = new Node(20);
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    head = newNode; // move head

    // insert another at beginning
    Node* newNode2 = new Node(30);
    newNode2->next = head;
    newNode2->prev = tail;
    tail->next = newNode2;
    head->prev = newNode2;
    head = newNode2;

    // display
    Node* ptr = head;
    cout << "List after inserting at front:" << endl;
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;

    return 0;
}