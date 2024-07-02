#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class CustomStack {
    private:
        stack<int> numStack;
        stack<int> minStack;

    public: 
        void push(int value){
            if(numStack.empty() || value < minStack.top()) minStack.push(value);
            numStack.push(value);
        }

        int pop(){
            if(numStack.empty()) return -1;
            int value = numStack.top();
            if(value == minStack.top()) minStack.pop();
            numStack.pop();
            return value;
        }

        int getMin(){
            if(minStack.empty()) return -1;
            else return minStack.top();
        }
};

class CustomStack2 {
    private:
        stack<int> numStack;
        int curMin;

    public: 
        void push(int value){
            if(!numStack.empty() && value < curMin){
                numStack.push(2*value - curMin);
                curMin = value;
            }else {
                if(numStack.empty()) curMin = value;
                numStack.push(value);
            }
        }

        int pop(){
            if(numStack.empty()) return -1;

            int value = numStack.top();
            int result;
            numStack.pop();

            if(value<curMin){
                result = curMin;
                curMin = 2*curMin - value;
            }else result = value;

            return result;
        }

        int getMin(){
            if(numStack.empty()) return -1;
            else return curMin;
        }
};

int main(){
    CustomStack2 stack = CustomStack2();
    return 0;
}