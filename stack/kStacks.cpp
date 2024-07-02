#include <iostream>

using namespace std;

class KStacks {
    private: 
        int *stackArr, *next, *top;
        int arraySize, numOfStacks, freeSpot;

    public: 
        KStacks(int k, int n){
            arraySize = n;
            numOfStacks = k;
            stackArr = new int[n];
            top = new int[k];
            next = new int[n];

            fill(top, top+k, -1);

            for(int i=0;i<n-1;i++) next[i] = i+1;
            next[n-1] = -1;

            freeSpot = 0;
        }

        void push(int stackNum, int value){
            if(freeSpot == -1){
                cout << "Stack Overflow" << endl;
                return;
            }

            int index = freeSpot;

            freeSpot = next[index];

            stackArr[index] = value;

            next[index] = top[stackNum - 1];

            top[stackNum - 1] = index;

        }

        int pop(int stackNum){
            if(top[stackNum-1] == -1){
                cout << "Stack Underflow" << endl;
                return -1;
            }

            int index = top[stackNum - 1];

            top[stackNum - 1] = next[index];

            next[index] = freeSpot;

            freeSpot = index;

            return stackArr[index];
        }
};

int main(){

    return 0;
}