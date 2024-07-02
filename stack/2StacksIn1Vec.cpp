#include <iostream>
#include <vector>

using namespace std;

class VectorStack {
    private:
        vector<int> stackVec;
        int capacity1 = 0;
        int capacity2 = 0;

    public: 
        VectorStack() {}

        void push1(int value){
            stackVec.insert(stackVec.begin(), value);
            capacity1++;
        }

        void push2(int value){
            stackVec.insert(stackVec.end(), value);
            capacity2++;
        }

        int pop1(){
            if(capacity1 == 0) return -1;
            int value = stackVec[0];
            stackVec.erase(stackVec.begin());
            capacity1--;

            return value;
        }

        int pop2(){
            if(capacity2 == 0) return -1;
            int value = stackVec[stackVec.size() - 1];
            stackVec.pop_back();
            capacity2--;

            return value;
        }

        int size1(){
            return capacity1;
        }

        int size2(){
            return capacity2;
        }
};

int main(){
    VectorStack stack = VectorStack();
    
    stack.push1(12);
    stack.push1(11);

    cout << stack.size1() << endl;
    cout << stack.size2() << endl;  
    cout << stack.pop2() << endl;
    cout << stack.pop1() << endl;
    stack.push2(34);
    stack.push2(4);
    stack.push2(42);

    cout << stack.pop1() << endl;
    cout << stack.pop1() << endl;

    cout << stack.pop2() << endl;
    cout << stack.pop2() << endl;
    cout << stack.pop2() << endl;
    cout << stack.pop2() << endl;


    return 0;
}