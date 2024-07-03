#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> numQueue;
    numQueue.push(10);
    numQueue.push(20);
    cout << numQueue.front() << endl; 
    cout << numQueue.back() << endl;
    cout << numQueue.size() << endl;
    numQueue.pop();
    cout << numQueue.empty() << endl;
    cout << numQueue.front() << endl;
    cout << numQueue.back() << endl;
    numQueue.pop();
    cout << numQueue.empty() << endl;

    return 0;
}