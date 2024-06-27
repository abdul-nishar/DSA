#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertAtEnd(Node*& head, int value){
    Node* newNode = new Node(value);
    if(head == nullptr) head = newNode;
    else {
        Node* movingNode = head;
        while(movingNode->next != nullptr) movingNode = movingNode->next;
        movingNode->next = newNode;
    }
}

int sizeOfLinkedList(Node* head){
    int count = 0;
    while(head != nullptr) {count++; head = head->next;}

    return count;
}

Node* intersectionPointOfTwoLinkedList(Node* head1, Node* head2) {
    int size1 = sizeOfLinkedList(head1);
    int size2 = sizeOfLinkedList(head2);
    
    if(size1 > size2){
        int count = 0;
        while(count < size1 - size2) {head1 = head1->next;count++;}
    }else {
        int count = 0;
        while(count < size2 - size1) {head2 = head2->next;count++;}
    }

    while(head1 != nullptr || head2 != nullptr){
        if(head1 == head2) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr;
}

int main(){
    Node* head1 = nullptr;

    insertAtEnd(head1, 3);
    insertAtEnd(head1, 6);
    insertAtEnd(head1, 9);
    insertAtEnd(head1, 15);
    insertAtEnd(head1, 30);

    Node* head2 = nullptr;

    insertAtEnd(head2, 10);
    insertAtEnd(head2, 15);
    insertAtEnd(head2, 30);

    Node* meetingNode = intersectionPointOfTwoLinkedList(head1, head2);
    cout << meetingNode;
    return 0;
}