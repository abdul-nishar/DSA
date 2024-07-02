#include <iostream>
#include <vector>
using namespace std;

class VectorStack {
    private:
        vector<int> stack;
        int top;

    public:
        VectorStack() : top(-1) {}

        void push(int value) {
            stack.push_back(value);
            top++;
        }

        int pop(){
            if(top < 0) {cout << "Stack underflow!" << endl;return -1;}
            else {
                int value = stack[top];
                stack.pop_back();
                top--;
                return value;
            }
        }

        int peek(){
            if(top<0) {cout << "Stack is empty!" << endl;return -1;}
            else return stack[top];
        }

        bool isEmpty(){
            return top < 0;
        }

        int size(){
            return top;
        }
};

int main(){
    VectorStack stack = VectorStack();
    cout << boolalpha << stack.isEmpty()<<endl;
    cout << stack.pop()<<endl;
    stack.push(18);
    cout << stack.peek()<<endl;
    return 0;
}