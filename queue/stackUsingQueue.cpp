#include <iostream>
#include <queue>

using namespace std;

class CustomStack {
    private: 
        queue<int> stackQueue;
        queue<int> auxiliaryQueue;

    public: 
        CustomStack() {}

        int top() {
            return stackQueue.front();
        }

        int size() {
            return stackQueue.size();
        }

        void push(int value){
            if(stackQueue.empty()) stackQueue.push(value);
            else {
                while(!stackQueue.empty()){
                    auxiliaryQueue.push(stackQueue.front());
                    stackQueue.pop();
                }

                stackQueue.push(value);

                while(!auxiliaryQueue.empty()){
                    stackQueue.push(auxiliaryQueue.front());
                    auxiliaryQueue.pop();
                }
            }
        }

        int pop() {
            if(stackQueue.empty()) return -1;
            int value = stackQueue.front();
            stackQueue.pop();
            return value;
        }
};

int main(){

    return 0;
}