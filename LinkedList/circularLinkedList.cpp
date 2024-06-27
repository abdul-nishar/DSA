#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value): data(value), next(nullptr) {}
};

void insertAtBegin(Node*& head, int value){
    Node* newNode = new Node(value);
    if(head == nullptr) {head = newNode;head->next = head;}
    else {
        newNode->next = head->next;
        head->next = newNode;
        newNode->data = head->data;
        head->data = value;
    }
}

void deleteHead(Node*& head){
    if(head == nullptr) return;
    if(head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head->next;
        head->data = temp->data;
        head->next = temp->next;
        delete temp;
    }
}

void deleteKthNode(Node*& head, int k){
    if(head == nullptr) return;
    if(head->next == head) {delete head;head=nullptr;}
    else {
        int count = 1;
        Node* mover = head;
        while(count <= k - 1) {mover = mover->next;count++;}
        Node * temp = mover->next;
        mover->next = temp->next;
        delete temp;
    }
}

void insertAtEnd(Node*& head, int value){
    Node* newNode = new Node(value);
    if(head == nullptr){head = newNode;head->next = head;}
    else {
        newNode->data = head->data;
        newNode->next = head->next;
        head->data = value;
        head->next = newNode;
        head = newNode;
    }
}

void tranverseCircularLL(Node* head) {
    if(head == nullptr) return;
    else {
        Node* mover = head;
        while(mover->next != head){
            cout << mover->data << " ";
            mover = mover->next;
        }
        cout << mover->data << endl;
    }
}

int main(){
    Node* head = nullptr;
    insertAtEnd(head, 56);

    tranverseCircularLL(head);
    deleteKthNode(head, 1);
    tranverseCircularLL(head);

    return 0;
}