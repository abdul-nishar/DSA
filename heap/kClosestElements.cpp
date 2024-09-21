#include <iostream>
#include <queue>

using namespace std;

struct CompareFunc {
    int val;

    CompareFunc(int x) : val(x) {}

    bool operator()(const int& a, const int& b){
        return abs(val - a) > abs(val - b);
    }
};

void kClosestElements(int arr[], int n, int x, int k){
    priority_queue<int, vector<int>, CompareFunc> minHeap(x);

    int index = 0;

    for(; index<(n-k);index++) minHeap.push(arr[index]);

    for(; index < n; index++) {
        minHeap.push(arr[index]);
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}

int main(){
    int nums[] = {20,40,5,100,150};

    kClosestElements(nums, 5, 100, 3);

    return 0;
}