#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int element) {
    for (size_t i = 0; i < n; i++){
        if(arr[i] == element) return i;
    }
    
    return -1;
}

int main(){
    int numbersArray[] = {1,2,3,4,5,6};
    cout << linearSearch(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 5);
    return 0;
}