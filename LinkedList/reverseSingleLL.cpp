#include <iostream>
#include <vector>
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

void printAllNodes(Node* head){
    Node*mover = head;
    while(mover != nullptr) {
        cout << mover->data << ' ';
        mover = mover->next;
    }
}

void reverseSingleLL(Node*& head) {
    Node* mover = head;
    Node* prev = nullptr;
    
    while(mover != nullptr){
        Node* temp = mover->next;
        mover->next = prev;
        prev = mover;
        mover = temp;
    }

    head = prev;
}

int main(){
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 5);
    insertAtEnd(head, 20);
    insertAtEnd(head, 15);
    insertAtEnd(head, 25);

    printAllNodes(head);

    reverseSingleLL(head);
    
    printAllNodes(head);

    return 0;
}