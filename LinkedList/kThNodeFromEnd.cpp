#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertAtEnd(Node*& head, int value){
    Node* newNode = new Node(value);
    if(head == nullptr) head = newNode;
    else {
        Node* mover = head;
        while(mover->next != nullptr) mover = mover->next;
        mover->next = newNode;
    }
}

// Method - 1
void kThNodeFromEnd1(Node* head, int k){
    if(head == nullptr) return;
    Node* mover = head;
    int count = 0;
    while(mover != nullptr) {count++;mover = mover->next;}

    if(k > count){cout<<"No such node exists" << endl;return ;}
    else {
        while(count != k) {count--;head = head->next;}
        cout << head->data << endl;
        return;
    }
}

// Method - 2
void kThNodeFromEnd2(Node* head, int k){
    Node* rightMover = head;
    int count = 0;
    if(k <= 0) return;
    while(count < k) {
        count++;
        if(rightMover == nullptr) {cout << "No such node exists" << endl;return;}
        rightMover=rightMover->next;
    }

    Node* leftMover = head;
    while(rightMover != nullptr){
        leftMover = leftMover->next;
        rightMover = rightMover->next;
    }

    cout << leftMover->data << endl;
    return;
}

int main(){
    Node* head = nullptr;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    kThNodeFromEnd2(head, 0);

    return 0;
}