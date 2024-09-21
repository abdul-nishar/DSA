#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& v, int n, int index){
    int smallest = index, leftNode = 2 * index + 1, rightNode = 2 * index + 2;

    if(leftNode < n && v[leftNode] < v[smallest]) smallest = leftNode;
    if(rightNode < n && v[rightNode] < v[smallest]) smallest = rightNode;

    if(smallest != index){
        swap(v[smallest], v[index]);
        heapify(v, n, smallest);
    }
}

void buildMinHeap(vector<int>& vec){
    int n = vec.size();
    for(int i = (n-2)/2; i >= 0; i--) heapify(vec, n, i);
}


void printVec(vector<int>& heapVec){
    for(auto val : heapVec) cout << val << " ";
    cout << endl;
}

int main(){

    vector<int> vec = {10,5,20,2,4,8};

    buildMinHeap(vec);

    printVec(vec);

    return 0;
}