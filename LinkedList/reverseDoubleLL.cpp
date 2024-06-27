#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

void insertAtEnd(Node*& head, int value){
    Node* newNode = new Node(value);
    if(head == NULL) head = newNode;
    else {
        Node* mover = head;
        while(mover->next != nullptr) mover = mover->next;

        mover->next = newNode;
        newNode->prev = mover;
    }
}

void printLinkedList(Node*& head){
    Node* mover = head;
    if(mover == NULL) return;
    while(mover->next != nullptr){
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << mover->data << endl;
}

void reverseLinkedList(Node*& head){
    Node* curHead = head;
    Node* prev = nullptr;
    while(curHead->next != nullptr){
        prev = curHead->next;
        curHead->next = curHead->prev;
        curHead->prev = prev;
        curHead = prev;
    }

    curHead->next = curHead->prev;
    curHead->prev = nullptr;

    head = curHead;
}


int main(){
    Node* head = nullptr;
    insertAtEnd(head, 2);
    insertAtEnd(head, 10);
    insertAtEnd(head, 56);
    insertAtEnd(head, 34);

    printLinkedList(head);
    reverseLinkedList(head);
    printLinkedList(head);
    return 0;
}