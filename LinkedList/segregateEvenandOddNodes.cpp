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

void segregateEvenandOddNodes(Node*& head) {
    Node* evenStart = nullptr;
    Node* evenEnd = nullptr;
    Node* oddStart = nullptr;
    Node* oddEnd = nullptr;
    Node* mover = head;

    while(mover!=nullptr){
        if(mover->data % 2 == 0){
            if(evenStart == nullptr){
                evenStart = mover;
                evenEnd = evenStart;
            }else {
                evenEnd->next = mover;
                evenEnd = mover;
            }
        }else{
            if(oddStart == nullptr){
                oddStart = mover;
                oddEnd = oddStart;
            }else{
                oddEnd->next = mover;
                oddEnd = mover;
            }
        }
        mover = mover->next;
    }

    if(evenStart == nullptr || oddStart == nullptr) return;

    evenEnd->next = oddStart;
    oddEnd->next = nullptr;

    head = evenStart;
}

int main(){
    Node* head = nullptr;

    insertAtEnd(head, 17);
    insertAtEnd(head, 15);
    insertAtEnd(head, 8);
    insertAtEnd(head, 12);
    insertAtEnd(head, 5);


    printAllNodes(head);
    segregateEvenandOddNodes(head);
    printAllNodes(head);

    return 0;
}