#include <iostream>
#include <unordered_map>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* arb;

    Node(int value) : data(value), next(nullptr), arb(nullptr) {}
};

Node* insertAtEnd(Node*& head, int value){
    Node* newNode = new Node(value);

    if(head == nullptr) head = newNode;
    else {
        Node* mover = head;
        while(mover->next != nullptr) mover = mover->next;
        mover->next = newNode;
    }

    return newNode;
}

void printAllNodes(Node* head){
    if(head == nullptr) return;
    Node*mover = head;
    while(mover != nullptr) {
        cout << mover->data << ' ';
        if(mover->arb != nullptr) cout << mover->arb->data << endl;
        else cout << "nullptr" << endl;
        mover = mover->next;
    }
    cout << endl;
}

// Time Complexity - O(n) and Space Complexity - O(n)
Node* cloneWithRandomPointer1(Node* head) {
    unordered_map<Node*, Node*> nodeMap;

    Node* newHead = nullptr;
    Node* mover = head;

    while(mover != nullptr) {
        Node* newNode = new Node(mover->data);
        if(mover == head) newHead = newNode;
        nodeMap[mover] = newNode;
        mover = mover->next;
    }

    while(head != nullptr){
        Node* curAddress = nodeMap[head];
        if(head->next!=nullptr) curAddress->next = nodeMap[head->next];
        if(head->arb != nullptr) curAddress->arb = nodeMap[head->arb];

        head = head->next;
    }

    return newHead;
}

// Time Complexity - O(n) and Space Complexity - O(1)
Node* cloneWithRandomPointer2(Node* head) {
    Node* mover = head;
    while(mover!=nullptr){
        Node* temp = mover->next;
        Node* newNode = new Node(mover->data);

        newNode->next = mover->next;
        mover->next = newNode;

        mover = temp;
    }

    mover = head;
    while(mover != nullptr){
        if (mover->arb != nullptr) {
            mover->next->arb = mover->arb->next;
        } else {
            mover->next->arb = nullptr;
        }
        mover = mover->next->next;
    }

    Node* newHead = head->next;
    mover = head;
    Node* cloneMover = newHead;
    
    while (mover != nullptr) {
        mover->next = mover->next->next;
        if (cloneMover->next != nullptr) {
            cloneMover->next = cloneMover->next->next;
        }
        mover = mover->next;
        cloneMover = cloneMover->next;
    }

    return newHead;
}

int main(){
    Node* head = nullptr;

    Node* node1 = insertAtEnd(head, 1);
    Node* node2 = insertAtEnd(head, 2);
    Node* node3 = insertAtEnd(head, 3);
    Node* node4 = insertAtEnd(head, 4);
    Node* node5 = insertAtEnd(head, 5);

    node1->arb = node3;
    node2->arb = node1;
    node5->arb = node5;

    printAllNodes(head);

    Node* newHead = cloneWithRandomPointer2(head);

    printAllNodes(newHead);

    return 0;
}