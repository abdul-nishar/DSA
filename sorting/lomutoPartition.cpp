#include <iostream>
using namespace std;

void lomutoPartition(int arr[], int n, int p) {
    swap(arr[p], arr[n-1]);
    int pivot = arr[n-1];
    int i = -1;
    for(int j = 0; j < n-1; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[n-1]);
}

int main(){
    int numbersArray[] = {50,30,20,10,5,11};
    lomutoPartition(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 2);
    for(int i=0; i<6;i++) cout << numbersArray[i] << " ";
    return 0;
}