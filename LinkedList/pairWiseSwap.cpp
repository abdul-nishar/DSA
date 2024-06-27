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
    if(head == nullptr) return;
    Node*mover = head;
    while(mover != nullptr) {
        cout << mover->data << ' ';
        mover = mover->next;
    }
    cout << endl;
}

void pairWiseSwap(Node*& head) {
    Node* prev = nullptr;
    
    Node* mover = head;
    while(mover != nullptr && mover->next != nullptr){
        Node* temp = mover->next->next;
        mover->next->next = mover;
        
        if(prev!=nullptr) prev->next = mover->next;
        else {
            head = mover->next;
        }
        
        prev = mover;
        
        mover = temp;
    }
    
    if(mover!=nullptr) prev->next = mover;
    else prev->next = nullptr;
}

int main(){
    Node* head = nullptr;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);

    printAllNodes(head);
    
    pairWiseSwap(head);

    printAllNodes(head);
    return 0;
}