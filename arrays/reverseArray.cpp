#include <iostream>

using namespace std;

void reverseArray(int *arr, int n){
    for (int i = 0; i < n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int main() {
    int numbersArray[] = {8,3,5,2,51,12};
    reverseArray(numbersArray,sizeof(numbersArray) / sizeof(int)); 
    for (int i = 0; i < sizeof(numbersArray) / sizeof(int); i++) {
        cout<<numbersArray[i]<<' ';
    }
    return 0;
}