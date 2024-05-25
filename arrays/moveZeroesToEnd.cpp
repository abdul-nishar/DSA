#include <iostream>

using namespace std;

void removeZeroes(int *arr, int n){
    int res = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            swap(arr[res],arr[i]);
            res++;
        }
    }
    
}

int main() {
    int numbersArray[] = {0,0,0,1,0,0,0,2,0};
    removeZeroes(numbersArray, 9);
    for(int i = 0; i < sizeof(numbersArray)/sizeof(int);i++){
        cout<<numbersArray[i]<<endl;
    }
}