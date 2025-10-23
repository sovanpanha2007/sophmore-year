#include "CDLLp.hpp"

int main() {
    CircularDoublyLinkedList list;
    list.insertBack(10);
    list.insertBack(20);
    list.deleteFront();
    list.display();
    return 0;
};