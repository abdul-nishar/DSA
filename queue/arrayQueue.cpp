#include <iostream>

using namespace std;

class ArrayQueue {
    private: 
    int *arr;
    // queueSize keeps count of the number of elements so that we don't modify the already exisiting values
    int front, back, capacity, queueSize;

    public: 
    
    // Construction Function
    ArrayQueue(int cap){
        arr = new int[cap];
        capacity = cap;
        front = queueSize = 0;
        back = -1;
    }

    // Deconstructor Function
    ~ArrayQueue(){
        delete[] arr;
    }

    bool isFull(){
        return queueSize == capacity;
    }

    bool isEmpty(){
        return queueSize == 0;
    }
    
    void push(int value){
        if(isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        back = (back + 1) % capacity; // This expression is necessary to point to the front if front exceeds capacity i.e. we are using a cirular array
        arr[back] = value;
        queueSize++;
    }

    int pop(){
        if(isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        queueSize--;

        return value;
    }

    int peekFront(){
        return isEmpty() ? -1 : arr[front];
    }

    int peekBack(){
        return isEmpty() ? -1 : arr[back];
    }

    int size(){
        return queueSize;
    }

};

int main(){
    ArrayQueue queue = ArrayQueue(7);
    cout << queue.size() << endl;
    queue.push(1);
    queue.push(2);
    cout << queue.peekBack() << endl;
    queue.push(3);
    queue.push(4);
    cout << queue.peekFront() << endl;
    cout << queue.size() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    queue.push(5);
    cout << queue.peekBack() << endl;
    queue.push(6);
    cout << queue.size() << endl;
    queue.push(7);
    queue.push(8);
    queue.push(9);
    queue.push(10);

}