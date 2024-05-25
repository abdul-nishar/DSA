#include <iostream>

using namespace std;

int leadersInArray(int arr[], int n){
    int currentLeader = arr[n-1];
    int count = 0;
    for(int i = n-2; i >= 0; i--){
        if(currentLeader < arr[i]){
            swap(arr[n-1-count], currentLeader);
            currentLeader = arr[i];
            count++;
        }
    }

    swap(arr[n-1-count], currentLeader);

    return n - 1 - count;
}

int main() {
    int numbersArray[] = { 7,10,4,3,6,5,2};
    int leaders = leadersInArray(numbersArray, sizeof(numbersArray)/sizeof(int));
    for(int i=leaders; i<sizeof(numbersArray)/sizeof(int);i++) {
        cout<<numbersArray[i]<<" ";
    }
}