#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedListQueue {
    private : 
        Node *head, *tail;
        int size;

    public : LinkedListQueue() : head(nullptr), tail(nullptr), size(0) {}

    void push(int value){
        Node *newNode = new Node(value);
        if(size==0) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    int pop(){
        if(size==0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node *temp = head;
        int value = temp->data;
        head = head->next;
        size--;
        delete temp;
        return value;
    }

    int front(){
        if(size==0) return -1;
        return head->data;
    }

    int back(){
        if(size==0) return -1;
        return tail->data;
    }

    int queueSize(){
        return size;
    }
};

int main(){
    LinkedListQueue queue = LinkedListQueue();

    queue.push(18);
    queue.push(19);
    queue.push(20);
    cout << queue.front() << endl;
    cout << queue.back() << endl;
    cout << queue.pop() << endl;
    cout << queue.front() << endl;
    cout << queue.pop() << endl;
    cout << queue.front() << endl;
    cout << queue.back() << endl;
    cout << queue.pop() << endl;
    cout << queue.front() << endl;
    cout << queue.back() << endl;


    return 0;
}