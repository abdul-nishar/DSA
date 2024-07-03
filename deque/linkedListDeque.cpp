#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class LinkedListDeque {
    private:
        Node *head, *tail;
        int dequeSize;

    public: 
        LinkedListDeque(int cap) {
            head = tail = nullptr;
            dequeSize = 0;
        }

        bool isEmpty() {
            return dequeSize == 0;
        }

        void insertFront(int value){
            Node* newNode = new Node(value);
            if(isEmpty()) head = tail = newNode;
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            dequeSize++;
        }

        void insertBack(int value){
            Node* newNode = new Node(value);
            if(isEmpty()) head = tail = newNode;
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            dequeSize++;
        }

        int deleteFront(){
            if(isEmpty()) {
                cout << "Deque Underflow!" << endl;
                return -1;
            }else {
                Node *temp = head;
                int value = temp->data;
                if(dequeSize == 1){
                    head = tail = nullptr;
                    delete temp;
                }else {
                    head = head->next;
                    head->prev = nullptr;
                    delete temp;
                }
                dequeSize--;
                return value;
            }
        }

        int deleteBack(){
            if(isEmpty()) {
                cout << "Deque Underflow!" << endl;
                return -1;
            }else {
                Node *temp = tail;
                int value = temp->data;
                if(dequeSize == 1){
                    head = tail = nullptr;
                    delete temp;
                }else {
                    tail = tail->prev;
                    tail->next = nullptr;
                    delete temp;
                }
                dequeSize--;
                return value;
            }
        }

        int getFront(){
            if(isEmpty()) return -1;
            else return head->data;
        }

        int getBack(){
            if(isEmpty()) return -1;
            else return tail->data;
        }

        int size(){
            return dequeSize;
        }
};

int main(){
    LinkedListDeque deq = LinkedListDeque(9);

    deq.insertFront(14);
    deq.insertFront(17);
    deq.insertBack(45);
    deq.insertBack(78);

    cout << deq.deleteBack() << endl;
    cout << deq.deleteFront() << endl;

    cout << deq.getBack() << endl;
    cout << deq.getFront() << endl;


    return 0;
}