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

void removeLoop(Node* head){
    Node* fast = head;
    Node* slow = head;

    // Loop Detection Logic
    
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    
    // Case if loop doesn't exist
    if(slow!=fast) return;
    
    // Loop Removal Logic
    slow = head;
    // Case if the slow and fast meet at the head itself
    if (slow == fast) {
        while (fast->next != slow) {
            fast = fast->next;
        }
    } else {
        while(fast->next!=slow->next){
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    fast->next = nullptr;
}

int main(){
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    Node* begin = insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    Node* end = insertAtEnd(head, 60);

    removeLoop(head);
    return 0;
}