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

// Naive Implementation
// Node* middleNode(Node* head){
//     if(head == nullptr) return nullptr;
//     int count = 0;
//     Node* mover = head;
//     while(mover!=nullptr) {count++;mover = mover->next;}

//     count = count/2 + 1;

//     while(count > 1){
//         head = head->next;
//         count--;
//     }

//     return head;
// }

// Efficient Implementation
void middleNode(Node* head){
    if(head == nullptr) return;
    Node* fast = head;
    Node* slow = head;
    while(fast!=nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    cout << slow->data << endl;
}

int main(){
    Node* head = nullptr;
    insertAtEnd(head,10);

    middleNode(head);
}