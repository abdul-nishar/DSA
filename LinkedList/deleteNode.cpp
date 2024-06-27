#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
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
        mover = mover->next;
    }
    cout << endl;
}

// This method will not work if the node to be deleted is the last node in the list
void deleteNode(Node* node) {
    Node* temp = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    delete temp;
}

int main(){
    Node* head = nullptr;

    Node* node1 = insertAtEnd(head, 10);
    Node* node2 = insertAtEnd(head, 20);
    Node* node3 = insertAtEnd(head, 30);
    Node* node4 = insertAtEnd(head, 40);
    Node* node5 = insertAtEnd(head, 25);

    printAllNodes(head);

    deleteNode(node3);

    printAllNodes(head);

    return 0;
}