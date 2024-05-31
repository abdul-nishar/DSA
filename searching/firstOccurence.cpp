#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int element){
    int low = 0, high = n-1;

    while(low<=high){
        int mid = (low+high)/2;
        if( arr[mid] == element && (mid==0 || arr[mid-1]<element)) return mid;
        else if(arr[mid] < element) low = mid+1;
        else high = mid-1;
    }

    return -1;
}

int main(){
    int numbersArray[] = {15,15,15};
    cout << firstOccurrence(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 15);
    return 0;
}