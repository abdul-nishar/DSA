#include <iostream>
using namespace std;

int sortedRotatedArray(int arr[], int n, int element) {
    int low=0, high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == element) return mid;
        else if(arr[mid]>element && arr[n-1]<element) high = mid-1;
        else low = mid+1;
    }

    return -1;
}

int main(){
    int numbersArray[] = {10,20,40,60,5, 8};
    cout << sortedRotatedArray(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 6);
    return 0;
}