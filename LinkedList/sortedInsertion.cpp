#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void sortedInsertion(Node*& head, int value){
    Node* newNode = new Node(value);
    if(head==nullptr) head = newNode;
    else if(head->data > value) {newNode->next = head; head = newNode;}
    else {
        Node* mover = head;
        while(mover->next != nullptr && mover->next->data < value) {mover = mover->next;}
        
        newNode->next = mover->next;
        mover->next = newNode;
    }
}

void printAllNodes(Node* head){
    if(head == nullptr) return;
    Node* mover = head;
    while(mover != nullptr){
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}


int main(){
    Node* head = nullptr;
    
    sortedInsertion(head, 10);
    sortedInsertion(head, 40);
    sortedInsertion(head, 5);
    sortedInsertion(head, 20);
    sortedInsertion(head, 50);
    sortedInsertion(head, 1);

    printAllNodes(head);
    return 0;
}