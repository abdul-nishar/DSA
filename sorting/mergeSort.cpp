#include <iostream>
using namespace std;

void merge(int array[], int left, int mid, int right){
 
    int * leftArray = new int [mid - left + 1];
    int * rightArray = new int [right - mid];
 
    for (auto i = 0; i < mid - left + 1; i++) leftArray[i] = array[left + i];
    for (auto j = 0; j < right - mid; j++) rightArray[j] = array[mid + 1 + j];
 
    int indexOfleftArray = 0,indexOfRightArray= 0,indexOfMergedArray= left;
 
    while (indexOfleftArray < (mid-left+1)
           && indexOfRightArray < right-mid) {
        if (leftArray[indexOfleftArray]
            <= rightArray[indexOfRightArray]) {
            array[indexOfMergedArray]
                = leftArray[indexOfleftArray];
            indexOfleftArray++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfRightArray];
            indexOfRightArray++;
        }
        indexOfMergedArray++;
    }

    while (indexOfleftArray < mid - left + 1) {
        array[indexOfMergedArray]
            = leftArray[indexOfleftArray];
        indexOfleftArray++;
        indexOfMergedArray++;
    }

    while (indexOfRightArray < right - mid) {
        array[indexOfMergedArray]
            = rightArray[indexOfRightArray];
        indexOfRightArray++;
        indexOfMergedArray++;
    }
    
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int arr[],int left, int right) {
    if(right > left){
        int mid = (left + right)/2;
        mergeSort(arr, 0, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int numbersArray[] = {10,15,20,11,30};
    mergeSort(numbersArray, 0, sizeof(numbersArray)/sizeof(numbersArray[0]) - 1);
    for(auto value  : numbersArray) cout << value << " ";
    return 0;
}