#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

class CDNode {
public:
    int data;
    CDNode* prev;
    CDNode* next;

    CDNode(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class CircularDoublyLinkedList {
private:
    CDNode* head;

public:
    // Constructor
    CircularDoublyLinkedList() : head(nullptr) {}

    // Destructor
    ~CircularDoublyLinkedList() {
        if (head == nullptr) return;

        CDNode* current = head->next;
        while (current != head) {
            CDNode* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
        head = nullptr;
    }

    // Insert at the front
    void insertFront(int value) {
        CDNode* newNode = new CDNode(value);

        if (head == nullptr) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }

        CDNode* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at the back
    void insertBack(int value) {
        CDNode* newNode = new CDNode(value);

        if (head == nullptr) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }

        CDNode* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    // Delete from the front
    void deleteFront() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
            return;
        }

        CDNode* tail = head->prev;
        CDNode* temp = head;

        head = head->next;
        head->prev = tail;
        tail->next = head;

        delete temp;
    }

    // Delete from the back
    void deleteBack() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
            return;
        }

        CDNode* tail = head->prev;
        CDNode* newTail = tail->prev;

        newTail->next = head;
        head->prev = newTail;

        delete tail;
    }
    //display
    void display() const {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        CDNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

#endif
