#include <iostream>
#include <queue>
#include <functional>

using namespace std;

void sortKSortedArr(int arr[], int k, int n){
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<=k;i++) pq.push(arr[i]);

    int index = 0;

    for(int i=k+1;i<n;i++){
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while(!pq.empty()){
        arr[index++] = pq.top();
        pq.pop();
    }
}

void printArr(int nums[], int n){
    for(int i=0;i<n;i++) cout << nums[i] << " ";
    cout << endl;
}

int main(){

    int nums[] = {9,8,7,18,19,17};

    int n = sizeof(nums)/sizeof(nums[0]);

    printArr(nums, n);

    sortKSortedArr(nums, 2, n);

    printArr(nums, n);

    return 0;
}