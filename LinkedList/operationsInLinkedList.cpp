#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
    private: Node* head;

    public: 
        LinkedList() : head(nullptr) {}

        Node* provideHead() { return head; }

        void insertAtBegin(int value){
            Node* newHead = new Node(value);
            newHead->next = head;
            head = newHead;
        }

        // While deleting a node, we need to deallocate the memory
        void deleteAtBegin(){
            Node* newHead = head->next;
            delete head;
            head = newHead;
        }

        void insertAtEnd(int value){
            Node* tail = new Node(value);
            if(head == nullptr) head = tail;
            else {
                Node* mover = head;
                while(mover->next != nullptr) mover = mover->next;
                mover->next=tail;
            }
        }

        void deleteAtEnd(){
            if(head == nullptr) return;
            else if(head->next == nullptr) head = nullptr;
            else {
                Node* mover = head;
                while(mover->next->next != nullptr) mover = mover->next;
                delete mover->next;
                mover->next = nullptr;
            }
        }

        void insertAfterNode(int value, int node){
            Node* newNode = new Node(value);
            if(head == nullptr) head = newNode;
            else {
                Node* mover = head;
                while(mover->data != node) mover = mover->next;
                newNode->next = mover->next;
                mover->next = newNode;
            }
        }

        void deleteAfterNode(int node) {
            if(head == nullptr) return;
            else {
                Node* mover = head;
                while(mover->data != node) mover = mover->next;
                Node* next = mover->next->next;
                delete mover->next;
                mover->next = next;
            }
        }

        int searchNode(int value){
            int count = 1;
            Node* mover = head;
            while(mover->next != nullptr){
                if(mover->data == value) return count;
                mover = mover->next;
                count++;
            }
            if(mover->data == value) return count;
            return -1;
        }

        void printAllNodes(){
            Node*mover = head;
            while(mover->next != nullptr) {
                cout << mover->data << " ";
                mover = mover->next;
            }
            cout << mover->data << endl;
        }
};

void recursiveTranveral(Node* node){
    cout << node->data << " ";
    if(node->next == nullptr) return;
    recursiveTranveral(node->next);
}


int main(){
    LinkedList table = LinkedList();
    table.insertAtEnd(8);
    table.insertAtEnd(9);
    table.insertAtEnd(10);
    table.insertAtEnd(15);
    table.insertAtBegin(2);
    table.insertAfterNode(12,10);
    table.printAllNodes();
    cout << table.searchNode(32) << endl;

    table.deleteAtBegin();
    table.printAllNodes();
    table.deleteAtEnd();
    table.printAllNodes();
    table.deleteAfterNode(9);

    recursiveTranveral(table.provideHead());
    return 0;
}

