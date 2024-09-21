#include <iostream>
#include <vector>

using namespace std;

void heapify(int index, vector<int>& heapVec){
    int smallest = index, leftNode = 2 * index + 1, rightNode = 2 * index + 2;

    if(leftNode < heapVec.size() && heapVec[leftNode] < heapVec[smallest]) smallest = leftNode;
    if(rightNode < heapVec.size() && heapVec[rightNode] < heapVec[smallest]) smallest = rightNode;

    if(smallest != index){
        swap(heapVec[index], heapVec[smallest]);
        heapify(smallest, heapVec);
    }
}

void extractMin(vector<int>& heapVec){
    if(heapVec.empty()) return;

    heapVec[0] = *(heapVec.end() - 1);

    heapVec.pop_back();

    heapify(0, heapVec);
}

void printVec(vector<int>& heapVec){
    for(auto val : heapVec) cout << val << " ";
    cout << endl;
}

int main(){

    vector<int> vec = {20,25,30,35,40,80,32,100,70,60};
    
    printVec(vec);

    extractMin(vec);

    printVec(vec);

    return 0;
}