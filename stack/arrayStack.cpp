#include <iostream>
using namespace std;

class ArrayStack {
    private:
        int capacity;
        int* arrPointer;
        int top;

    public:
        ArrayStack(int cap) {
            capacity = cap;
            arrPointer = new int[capacity];
            top = -1;
        }

        bool push(int value){
            if(top < capacity - 1) {arrPointer[++top] = value;return true;}
            else  {cout << "Stack overflow!" << endl;return false;}
        }

        int pop(){
            if(top < 0) {cout << "Stack underflow!" << endl;return -1;}
            else return arrPointer[top--];
        }

        int peek(){
            if(top<0) {cout << "Stack is empty!" << endl;return -1;}
            else return arrPointer[top];
        }

        bool isEmpty(){
            return top<0;
        }

        int size(){
            return top - 1;
        }
};

int main(){
    ArrayStack stack = ArrayStack(5);
    cout << stack.isEmpty()<<endl;
    cout << stack.pop()<<endl;
    cout << stack.push(18) <<endl;
    cout << stack.peek()<<endl;
    return 0;
}