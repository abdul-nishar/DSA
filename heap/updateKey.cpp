#include <iostream>
#include <vector>

using namespace std;

void updateKey(int index, vector<int>& heapVec, int value){
    heapVec[index] = value;

    int parent = (index - 1) / 2;

    while(parent >= 0 && heapVec[parent] > heapVec[index]){
        swap(heapVec[parent], heapVec[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void printVec(vector<int>& heapVec){
    for(auto val : heapVec) cout << val << " ";
    cout << endl;
}

int main(){

    vector<int> vec = {10,20,40,80,100,70};
    
    printVec(vec);

    updateKey(3, vec, 5);

    printVec(vec);

    return 0;
}