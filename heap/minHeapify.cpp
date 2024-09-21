#include <iostream>
#include <vector>

using namespace std;

void heapify(int index, vector<int>& heapVec){
    int smallest = index, leftNode = 2 * index + 1, rightNode = 2 * index + 2;

    if(index < heapVec.size() && heapVec[leftNode] < heapVec[smallest]) smallest = leftNode;
    if(index < heapVec.size() && heapVec[rightNode] < heapVec[smallest]) smallest = rightNode;

    if(smallest != index) {
        swap(heapVec[smallest], heapVec[index]);
        heapify(smallest, heapVec);
    }
}

int main(){

    vector<int> nums = {40,20,30,35,25,80,32,100,70,60};

    for(auto val : nums) cout << val << " ";

    cout << endl;

    heapify(0, nums);

    for(auto val : nums) cout << val << " ";

    return 0;
}