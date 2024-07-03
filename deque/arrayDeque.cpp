#include <iostream>

using namespace std;

class ArrayDeque {
    private:
        int *arr;
        int front, back, dequeSize, capacity;

    public: 
        ArrayDeque(int cap) {
            capacity = cap;
            arr = new int[capacity];
            front = back = -1;
            dequeSize = 0;
        }

        ~ArrayDeque() {
            delete[] arr;
        }

        bool isEmpty(){
            return dequeSize == 0;
        }

        bool isFull(){
            return dequeSize == capacity;
        }

        void insertFront(int value){
            if(isFull()){
                cout << "Deque overflow!" << endl;
                return;
            }

            if(front == -1) front = back = 0;
            // This is done so that the front does not become negative as it is an index
            else front = (front - 1 + capacity) % capacity;

            arr[front] = value;
            dequeSize++;
        }

        void insertBack(int value){
            if(isFull()){
                cout << "Deque overflow!" << endl;
                return;
            }

            if(back == -1) front = back = 0;
            else back = (back + 1) % capacity;

            arr[back] = value;
            dequeSize++;
        }

        int deleteFront(){
            if(isEmpty()){
                cout << "Deque underflow!" << endl;
                return -1;
            }

            int value = arr[front];

            if(front == back) front = back = -1;
            else front = (front + 1) % capacity;

            dequeSize--;

            return value;
        }

        int deleteBack(){
            if(isEmpty()) {
                cout << "Deque underflow!" << endl;
                return -1;
            }
            
            int value = arr[back];

            if(back == front) front = back = -1;
            else back = (back - 1 + capacity) % capacity;

            dequeSize--;

            return value;
        }

        int getFront(){
            if(isEmpty()) return -1;
            else return arr[front];
        }

        int getBack(){
            if(isEmpty()) return -1;
            else return arr[back];
        }

        int size(){
            return dequeSize;
        }
};

int main(){
    ArrayDeque deq = ArrayDeque(9);
    return 0;
}