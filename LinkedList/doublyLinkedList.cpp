#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
    private: Node* head; Node* tail;

    public: 
        DoubleLinkedList() : head(nullptr), tail(nullptr) {};

        void insertAtBegin(int value){
            Node* newNode = new Node(value);
            if(head == nullptr) {head = newNode;tail = newNode;}
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        void deleteHead(){
            if(head==nullptr)return;
            if(head->next==nullptr){
                head=nullptr;
                tail=nullptr;
                return;
            }  
            Node* newHead = head->next;
            delete head;
            head = newHead;
            head->prev = nullptr;
        }

        void insertAtEnd(int value){
            Node* newNode = new Node(value);
            if(tail == nullptr) {tail = newNode;head = newNode;}
            else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }

        void deleteAtEnd(){
            if(tail == nullptr) return;
            if(tail->prev==nullptr){
                tail=nullptr;
                head=nullptr;
                return;
            }
            Node* newTail = tail->prev;
            delete tail;
            tail = newTail;
            tail->next = nullptr;
        }

        void printFromStart(){
            if(head == nullptr) return;
            Node* mover = head;
            while(mover != nullptr){
                cout << mover->data << " ";
                mover = mover->next;
            }
            cout << endl;
        }

        void printFromEnd(){
            if(tail == nullptr) return;
            Node* mover = tail;
            while(mover != nullptr){
                cout << mover->data << " ";
                mover = mover->prev;
            }
            cout << endl;
        }
};

int main(){
    DoubleLinkedList sequence = DoubleLinkedList();
    sequence.insertAtEnd(1);
    sequence.insertAtEnd(2);
    sequence.insertAtEnd(3);
    sequence.insertAtEnd(4);

    sequence.insertAtBegin(0);

    sequence.printFromStart();
    sequence.printFromEnd();

    sequence.deleteHead();
    sequence.deleteAtEnd();
    sequence.deleteHead();
    sequence.deleteAtEnd();
    sequence.deleteAtEnd();


    sequence.printFromStart();
    sequence.printFromEnd();
    return 0;
}