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

void reverseInGroupsOfK(Node*& head, int k) {
   Node* mover = head;
   Node* prevFirst = nullptr;
   bool isFirst = true;

   while(mover != nullptr) {
        Node* first = mover;
        Node* prev = nullptr;
        int count = 1;

        while(mover != nullptr && count <= k) {
            Node* temp = mover->next;
            mover->next = prev;
            prev= mover;
            mover = temp;
            count++;
        }

        if(isFirst) { head = prev; isFirst = false; }
        else { prevFirst->next = prev;}

        prevFirst = first;
   }

}

int main(){
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    insertAtEnd(head, 60);

    reverseInGroupsOfK(head, 3);

    printAllNodes(head);
    return 0;
}