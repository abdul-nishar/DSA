#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int data1) : data(data1),next(nullptr){}
};

Node* convertArr2LL(vector<int> vec){
    Node* head = new Node(vec[0]);
    Node* mover = head;
    for(int i=1;i<vec.size();i++){
        Node* newNode = new Node(vec[i]);
        mover->next = newNode;
        mover = newNode;
    }
    return head;
}

int main() {
    vector<int> x = {4,5,6,7,345,6,3};
    Node* head = convertArr2LL(x);
    Node* mover = head;
    
    while(mover != nullptr){
        cout << mover->data << " ";
        mover = mover->next;
    }
    return 0;
}