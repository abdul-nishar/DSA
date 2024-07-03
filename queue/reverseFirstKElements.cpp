#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Recursive Solution to reverese a queue
void reverseQueue(queue<int> &q){
    if(q.empty()) return;

    int value = q.front();
    q.pop();
    reverseQueue(q);
    q.push(value);
}

void reverseFirstKElements(queue<int> &q, int k){
    stack<int> kStack;

    if(q.empty()) return;

    while(kStack.size() < k){
        kStack.push(q.front());
        q.pop();
    }

    while(!kStack.empty()) {
        q.push(kStack.top());
        kStack.pop();
    }

    for(int i=0;i<q.size()-k;i++){
        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(){
    deque<int> initialValues = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    queue<int, deque<int>> q(initialValues);
    printQueue(q);
    reverseFirstKElements(q, 5);
    printQueue(q);
    
    return 0;
}