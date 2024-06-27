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

Node* mergeSortedLL(Node* head1, Node* head2) {
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;

    Node* newHead = nullptr;

    if(head1->data > head2->data){
        newHead = head2;
        head2 = head2->next;
    }else {
        newHead = head1;
        head1 = head1->next;
    }

    Node* prev = newHead;

    while(head1 != nullptr && head2 != nullptr) {
        if(head1->data > head2->data){
            prev->next = head2;
            head2 = head2->next;
        }else {
            prev->next = head1;
            head1 = head1->next;
        }
        prev = prev->next;
    }

    if(head2 == nullptr){
        prev->next = head1;
    }else if(head1 == nullptr){
        prev->next = head2;
    }

    return newHead;
}

Node * mergeKLists(Node *arr[], int K){
    Node* newHead = mergeSortedLL(arr[0],arr[1]);
    for(int i=2;i<K;i++){
        newHead = mergeSortedLL(newHead, arr[i]);
    }
    
    return newHead;
}

int main(){
    Node* head1 = nullptr;

    insertAtEnd(head1, 1);
    insertAtEnd(head1, 2);
    insertAtEnd(head1, 3);

    Node* head2 = nullptr;

    insertAtEnd(head2, 4);
    insertAtEnd(head2, 5);

    Node* head3 = nullptr;

    insertAtEnd(head3, 5);
    insertAtEnd(head3, 6);


    Node* head4 = nullptr;

    insertAtEnd(head4, 7);
    insertAtEnd(head4, 8);

    Node* nodeArr[] = {head1, head2, head3, head4};

    Node* newHead = mergeKLists(nodeArr, 4);

    printAllNodes(newHead);
    return 0;
}