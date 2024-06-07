#include <iostream>
using namespace std;


void heapify(int arr[], int n, int index){
    int largest = index, leftNode = 2*index + 1, rightNode = 2*index + 2;
    if(leftNode < n && arr[leftNode] > arr[largest]) largest = leftNode;
    if(rightNode < n && arr[rightNode] > arr[largest]) largest = rightNode;

    if(largest != index){
        swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for(int i = (n-2)/2; i>=0; i--) heapify(arr, n, i);
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr, n);
    for(int i =n-1;i>=0; i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0); // Here, we are passing i so that we decrease the size of the heap
    }
}

int main(){
    int numbersArray[] = {10,15,50,4,20};
    heapSort(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    for(int i=0; i<sizeof(numbersArray)/sizeof(numbersArray[0]);i++) cout << numbersArray[i] << " ";
    return 0;
}