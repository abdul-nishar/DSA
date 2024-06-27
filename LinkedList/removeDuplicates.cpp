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

void removeDuplicates(Node* head) {
    if(head == nullptr) return;
    Node*mover = head;
    while(mover->next != nullptr){
        if(mover->next->data != mover->data) mover = mover->next;
        else {
            Node* temp = mover->next;
            mover->next = mover->next->next;
            delete temp;
        }
    }
}

int main(){
    Node* head = nullptr;

    printAllNodes(head);

    removeDuplicates(head);

    printAllNodes(head);

    return 0;
}