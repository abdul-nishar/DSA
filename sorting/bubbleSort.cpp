#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

int main(){
    int numbersArray[] = {9,7,1,10,3,6,21,17,12};
    bubbleSort(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    for(auto values : numbersArray) cout << values << " ";
    return 0;
}