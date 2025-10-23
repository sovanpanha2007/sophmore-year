#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

struct DNode{
    int value;
    Node* next;
    Node* prev;
};


class linkedlist{
    private:

    Node* head;
    Node* temp;
    int n;


    public:

    linkedlist(){
        head = nullptr;
        n = 0;
    }

    int getn(){
        return n;
    }

    void insertFront(int val){
        Node* front = new Node{val,nullptr};
        front->next=head;
        head=front;
        n++;
    }

    void insertEnd(int val){
        if(n==0){
            insertFront(val);
            return;
        }
        traverse();
        Node* end = new Node{val,nullptr};
        temp->next=end;
        n++;
    }

    void insertMiddle(int val,int pos){
        if(pos>n){
            cout<<"Out of range!!";
            return;
        }

        if (pos==0){
            insertFront(val);
            return;
        }

        if (pos==n){
            insertEnd(val);
            return;
        }

        Node* mid = new Node{val,nullptr};
        temp = head;
        for (int i=0;i<pos;i++){
            temp=temp->next;
        }
        mid->next=temp->next;
        temp->next=mid;
        n++;
    }

    void deleteFront(){
        if (n==0){
            cout<<"No need to delete!!!";
            return;
        }
        temp = head;
        head = head->next;
        delete temp;
        n--;
    }

    void deleteEnd(){
        temp = head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=nullptr;
        delete temp;
        n--;

    }

    void deleteMiddle(int pos){
        if (pos==0){
            deleteFront();
            return;
        }

        if (pos==n-1){
            deleteEnd();
            return;
        }

        if (pos>n-1){
            cout<<"Out of range!!!";
            return;
        }
        temp = head;
        for (int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        delete temp;
        n--;
    }

    void swap(int pos1,int pos2){
        if (pos1>pos2){
            int temm= pos2;
            pos2=pos1;
            pos1=temm;
        }

        if(pos1==pos2){
            cout<<"No need to swap";
            return;
        }

        if (pos1>=n||pos2>=n){
            cout<<"Out of range!!";
            return;
        }

        Node* bef1=nullptr;
        Node* bef2=nullptr;
        Node* node1=head;
        Node* node2=head;
        
        for (int i=0;i<pos1;i++){
            bef1=node1;
            node1=node1->next;
        }
        for (int i=0;i<pos2;i++){
            bef2=node2;
            node2=node2->next;
        }

        bef1->next=node2;
        bef2->next=node1;

        Node* oth = node2->next;
        node2->next=node1->next;
        node1->next=oth;
        
    }

    void searchVal(int val){
        temp=head;
        int j=0;
        for (int i=0;i<n;i++){
            if (temp->value==val){
                cout<<val<<" at position "<<i<<endl;
                j++;
            }
            temp=temp->next;
        }
        if(j==0){
            cout<<val<<" not exist";
        }
    }

    void traverse(){
        temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
    }

    void print(){
        temp = head;
        while(temp!=NULL){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};