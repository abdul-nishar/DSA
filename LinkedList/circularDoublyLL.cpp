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
    if (head==nullptr) {head = newNode; head->next = head->prev = head;}
    else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
}

void printAllNode(Node* head){
    if(head==nullptr) return;
    else {
        Node* mover = head;
        while(mover->next != head) {cout << mover->data << " "; mover = mover->next;}

        cout << mover->data << endl;
    }
}

int main(){
    Node* head = nullptr;
    insertAtEnd(head, 13);
    insertAtEnd(head, 54);
    insertAtEnd(head, 78);
    printAllNode(head);

    return 0;
}