#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;

    Node(int value) : data(value), prev(nullptr) {}
};

class LinkedListStack {
    private: 
        Node* tail;
        int capacity = 0;

    public: 
        LinkedListStack() : tail(nullptr) {}

        void push(int value) {
            Node* newNode = new Node(value);
            if(tail == nullptr) {tail = newNode;capacity = 1;}
            else {
                newNode->prev = tail;
                tail = newNode;
                capacity++;
            }
        }

        int pop() {
            if(tail == nullptr) return -1;
            int value = tail->data;
            Node* temp = tail;
            tail = tail->prev;
            capacity--;
            delete temp;
            return value;
        }

        int top(){
            if(tail == nullptr) return -1;
            else return tail->data;
        }

        bool isEmpty(){
            if(tail == nullptr) return true;
            else return false;
        }

        int size() {
            return capacity;
        }
};

int main(){
    LinkedListStack stack = LinkedListStack();

    cout << boolalpha << stack.isEmpty() << endl;
    cout << stack.pop() << endl;
    stack.push(12);
    stack.push(11);
    cout << stack.top() << endl;
    stack.push(2);
    cout << stack.size() << endl;
    cout << stack.pop() << endl;
    cout << boolalpha << stack.isEmpty() << endl;

    return 0;
}