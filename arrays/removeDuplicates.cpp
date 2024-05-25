#include <iostream>

using namespace std;

int deleteDuplicates(int arr[], int n){
    int res = 1;

    for(int i=1; i<n; i++){
        if(arr[i]!=arr[res-1]) {
            arr[res] = arr[i];
            res++;
        }
    }

    return res;
}

int main(){
    int numbersArray[] = {10,20,20,30,30,30};
    int newSize = deleteDuplicates(numbersArray,sizeof(numbersArray) / sizeof(int)); 
    for (int i = 0; i < newSize; i++) {
        cout<<numbersArray[i]<<' ';
    }
    return 0;
}