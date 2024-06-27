#include <iostream>
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

bool areIdentical(struct Node *head1, struct Node *head2){
    while(head1 != nullptr && head2 != nullptr){
        if(head1->data != head2->data) return false;
        else {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    
    return head1 == nullptr && head2 == nullptr;
}


int main(){
    Node* head1 = nullptr;
    insertAtEnd(head1, 1);
    insertAtEnd(head1, 2);
    insertAtEnd(head1, 3);
    insertAtEnd(head1, 4);
    insertAtEnd(head1, 5);

    Node* head2 = nullptr;
    insertAtEnd(head2, 1);
    insertAtEnd(head2, 2);
    insertAtEnd(head2, 3);
    insertAtEnd(head2, 4);
    insertAtEnd(head2, 5);

    cout << areIdentical(head1, head2);

}