#include <iostream>
#include <queue>

using namespace std;

void printFibonnaci(int n){
    queue<int> fibQueue;

    fibQueue.push(0);
    fibQueue.push(1);

    for(int i=0;i<n;i++){
        int a = fibQueue.front();
        fibQueue.pop();
        int b = fibQueue.front();
        fibQueue.pop();

        fibQueue.push(b);
        fibQueue.push(a + b);

        cout << a << " ";
    }
}

int main(){
    printFibonnaci(20);
    return 0;
}