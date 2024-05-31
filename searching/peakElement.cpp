#include <iostream>
using namespace std;

int peakElement(int arr[], int n) {
    int low=0, high=n-1;
    int mid;

    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) break;
        else if(arr[mid]<arr[mid+1] && arr[mid+1] > arr[mid-1]) low = mid+1;
        else high = mid-1;
    }

    return arr[mid];
}

int main(){
    int numbersArray[] = { 5, 10, 20, 15};
    cout << peakElement(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    return 0;
}